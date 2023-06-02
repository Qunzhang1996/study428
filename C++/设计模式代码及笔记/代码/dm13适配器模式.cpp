#include <iostream>
using namespace std;

class Current18V
{
public:
	virtual void useCurrent18V() = 0;
};

class Current220V
{
public:
	void useCurrent220V()
	{
		cout << "now using 220V" << endl;
	}
};

class Adapter : public Current18V
{
public:
	Adapter(Current220V *current)
	{
		m_current = current;
	}

	virtual void useCurrent18V()
	{
		cout << "adaptor ";
		m_current->useCurrent220V();
	}

private:
	Current220V *m_current;
};

int main()
{
	// �û���18V�Ľӿ� �� �ӿ��������ڲ���220V��ѹ
	Current220V *current220 = new Current220V;

	// ֱ�ӵ���������
	Adapter *adapter = new Adapter(current220);
	adapter->useCurrent18V();

	delete current220;
	delete adapter;
}