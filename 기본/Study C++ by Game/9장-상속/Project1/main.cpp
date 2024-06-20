#include <iostream>

class Actor
{
	int height;
protected:
	int money;
public:
	int age;

	Actor(int h = 180, int m = 100, int a = 20) : height(h), money(m), age(a) {	}

protected:
	void print()
	{
		printf("height: %d, money: %d, age: %d\n", height, money, age);
	}
};

// Teacher : ��� ������ Actor // public, protected, private �ٲ㰡�� ����� �غ��� �� �� �ִ�
class Teacher : public Actor
{
	int careerYear;
public:
	
	void getOlder()
	{
		age += 1;
		printf("age: %d\n", age);
	}

	void raise(int plusM)
	{
		money += plusM;
		print();
	}

	void when(int year = 0)
	{
		careerYear = year;
	}
};

int main()
{
	Actor actor1;
	Teacher teacher1;
	Teacher teacher2;
	teacher2.age = 31;


	//actor1.print();
	//teacher1.print();

	teacher1.getOlder();
	//teacher1.print();
	
	teacher1.raise(200);
	teacher2.raise(-10);

	return 0;
}