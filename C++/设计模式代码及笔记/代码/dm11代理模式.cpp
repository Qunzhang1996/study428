#include <iostream>
using namespace std;

class Subject
{
public:
	virtual void sellbook() = 0;
};
class RealBookStore : public Subject
{
public:
	virtual void sellbook()
	{
		cout << "sell  book" << endl;
	}
};

// ����������ʵ�������
//////�̳з�ʽʵ�֣�
// class DangDang : public Subject
//{
// public:
//	virtual void sellbook()
//	{
//		Subject *sub = new RealBookStore;
//		//RealBookStore *rb = new RealBookStore;
//		dazhe();
//		sub->sellbook();
//	}
//	void dazhe()
//	{
//		cout << "����" << endl;
//	}
//
// private:
//	 //Subject *m_sub;
// };

// void main1()
//{
//	Subject *s = new DangDang;
//	s->sellbook();
//	delete s;
//
//	system("pause");
//	return;
// }

////��Ϸ�ʽʵ�֣�
class DangDang
{
public:
	DangDang()
	{
		m_sub = new RealBookStore;
	}
	void sellbook()
	{
		// ����ģʽ�� ��ʵ���ڲ������߼�
		// ���� ���������Ƿ���������ֻ�ȵ�
		dazhe();
		m_sub->sellbook();
	}
	void dazhe()
	{
		cout << "sale " << endl;
	}

private:
	Subject *m_sub;
};

int main()
{
	DangDang d;
	d.sellbook();
}