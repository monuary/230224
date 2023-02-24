//explicit을 반환형으로 복사 생성자를 정의하면, 묵시적 변환이 발생하지 않는다. 코드의 결과 예측에 도움을 준다.

//깊은 복사는 메모리 할당만 별개로 하는 방법이다. 소멸 시 문제 발생을 막을 수 있다.

#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
	enum{사원,주임,대리,과장};
	void show(int pos)
	{
		switch (pos)
		{
		case 사원:
			cout << "사원" << endl;
			break;
		case 주임:
			cout << "주임" << endl;
			break;
		case 대리:
			cout << "대리" << endl;
			break;
		case 과장:
			cout << "과장" << endl;
			break;
		default:
			break;
		}
	}
}

class Namecard
{
	char* name;		//포인트를 붙이면 한번에 정의가 불가능하다. char*name,company; 불가
	char* company;
	char* phone;
	int pos;
public:
	Namecard(const char* myname, const char* mycom, const char* mynum, int pos) :pos(pos)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		company = new char[strlen(mycom) + 1];
		strcpy(company, mycom);
		phone = new char[strlen(mynum) + 1];
		strcpy(phone, mynum);
	}
	Namecard(const Namecard& copy) :pos(copy.pos)
	{
		name = new char[strlen(copy.name) + 1];			//메모리가 할당된 부분만 따로 정의해준다.
		strcpy(name, copy.name);
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직위: "; COMP_POS::show(pos); cout << endl;
	}
	~Namecard()
	{
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main()
{
	Namecard 사원("LEE", "ABC", "000-1111-2222", COMP_POS::사원);
	Namecard copy1 = 사원;
	Namecard 주임("HONG", "ORG", "333-4444-5555", COMP_POS::주임);
	Namecard copy2 = 주임;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}