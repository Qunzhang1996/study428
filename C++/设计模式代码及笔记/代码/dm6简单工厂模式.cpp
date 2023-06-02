#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// �򵥹���ģʽ��������23�����ģʽ����
// ��Ҫʲô������ �������������ʲô����
// ���ǹ����������Ķ�����ǰ�̶��ˡ���Ҫ�����µĶ�������Ҫ�Ķ�ԭ���Ĵ��룬�ƻ��˿���ԭ��
// �����Ҫ��һ��ģʽ�� ����ģʽ

class Fruit
{
public:
	virtual void getFruit() = 0;

protected:
private:
};

class Banan : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am banana" << endl;
	}

protected:
private:
};

class Apple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am apple" << endl;
	}

protected:
private:
};

// ����
class Factory
{
public:
	Fruit *createFruit(const char *str)
	{
		if (strcmp(str, "banana") == 0)
		{
			return new Banan;
		}
		else if (strcmp(str, "apple") == 0)
		{
			return new Apple;
		}
		else
		{
			cout << "error" << endl;
		}
		return NULL;
	}

protected:
private:
};

int main()
{
	Factory *fac = new Factory;
	Fruit *fruit = NULL;

	fruit = fac->createFruit("banan"); // new banan
	fruit->getFruit();
	delete fruit;

	fruit = fac->createFruit("apple"); // new apple
	fruit->getFruit();
	delete fruit;

	delete fac;
}