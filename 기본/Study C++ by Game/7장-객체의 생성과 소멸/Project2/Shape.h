#pragma once
#include <iostream>
using namespace std;

struct Point {
	int x, y;
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) 
	{
		cout << "��(" << x << ", " << y << ") ������ \n";
	}

	~Point()
	{
		cout << "��(" << x << ", " << y << ") �Ҹ��� \n";
	}
};

class Circle {
	Point center;   // �� �߽�
	int radius;  // �� ������
public:
	Circle(int cx = 0, int cy = 0, int r = 0) : center(cx, cy), radius(r) 
	{
		cout << "��(������: " << radius << ") ������ \n";
	}

	~Circle()
	{
		cout << "��(������: " << radius << ") �Ҹ��� \n";
	}
};

