#include <iostream>
using namespace std;

// װ��ģʽ�� ����������װ

class Car
{
public:
	virtual void show() = 0;
};

// ����������~
class RunCar : public Car
{
public:
	virtual void show()
	{
		cout << "Run Car" << endl;
	}
};

// װ��  ����Ӿ�ĳ�   ��ɵĳ�
class SwimCar : public Car
{
public:
	SwimCar(Car *car)
	{
		m_car = car;
	}
	void swim()
	{
		cout << "Swim + ";
	}
	virtual void show()
	{
		swim();
		m_car->show();
	}

private:
	Car *m_car;
};

class FlyCar : public Car
{
public:
	FlyCar(Car *car)
	{
		m_car = car;
	}
	void fly()
	{
		cout << "Fly + ";
	}
	virtual void show()
	{
		fly();
		m_car->show();
	}

private:
	Car *m_car;
};

int main()
{
	Car *car = NULL;
	car = new RunCar();
	car->show();
	cout << endl;

	FlyCar *f = new FlyCar(car);
	f->show();
	cout << endl;

	SwimCar *s = new SwimCar(car);
	s->show();
	cout << endl;

	SwimCar *sf = new SwimCar(f);
	sf->show();
}