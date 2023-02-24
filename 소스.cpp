//explicit�� ��ȯ������ ���� �����ڸ� �����ϸ�, ������ ��ȯ�� �߻����� �ʴ´�. �ڵ��� ��� ������ ������ �ش�.

//���� ����� �޸� �Ҵ縸 ������ �ϴ� ����̴�. �Ҹ� �� ���� �߻��� ���� �� �ִ�.

#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
	enum{���,����,�븮,����};
	void show(int pos)
	{
		switch (pos)
		{
		case ���:
			cout << "���" << endl;
			break;
		case ����:
			cout << "����" << endl;
			break;
		case �븮:
			cout << "�븮" << endl;
			break;
		case ����:
			cout << "����" << endl;
			break;
		default:
			break;
		}
	}
}

class Namecard
{
	char* name;		//����Ʈ�� ���̸� �ѹ��� ���ǰ� �Ұ����ϴ�. char*name,company; �Ұ�
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
		name = new char[strlen(copy.name) + 1];			//�޸𸮰� �Ҵ�� �κи� ���� �������ش�.
		strcpy(name, copy.name);
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}
	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: "; COMP_POS::show(pos); cout << endl;
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
	Namecard ���("LEE", "ABC", "000-1111-2222", COMP_POS::���);
	Namecard copy1 = ���;
	Namecard ����("HONG", "ORG", "333-4444-5555", COMP_POS::����);
	Namecard copy2 = ����;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}