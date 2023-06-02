#include <iostream>
using namespace std;

// ����ʽ����ģʽ��   ֱ������ʵ��
class Singelton
{
private:
	Singelton()
	{
		cout << "Constructor" << endl;
	}

protected:
public:
	static Singelton *getInstance()
	{
		return m_sne;
	}

	// �ͷ��ڴ�
	static void freeInstance()
	{
		if (m_sne != NULL)
		{
			delete m_sne;
			m_sne = NULL;
			cout << "free memory!" << endl;
		}
	}

private:
	static Singelton *m_sne;
};

// ��̬������ʼ��
Singelton *Singelton::m_sne = new Singelton;

void main31()
{
	// ��̬�����ĵ���
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "p1 and p2 is same object" << endl;
	}
	else
	{
		cout << "p1 and p2 is different object" << endl;
	}

	Singelton::freeInstance();

	return;
}

int main()
{
	main31();
}