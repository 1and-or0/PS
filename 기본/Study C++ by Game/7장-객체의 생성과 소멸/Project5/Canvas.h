#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

#define MAXLINES 100

class Canvas {
	string line[MAXLINES];
	int xMax, yMax;
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny)
	{
		for (int y = 0; y < yMax; ++y)
		{
			line[y] = string(xMax * 3, '*'); // xMax * 2 �� ĭ�� 2����Ʈ ���ڸ� ����ؼ�
		}
	}

	void draw(int x, int y, string val)
	{
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
		{
			line[y].replace(x * 2, 2, val);
		}
	}

	void clear(string val = ".")
	{
		for (int y = 0; y < yMax; ++y)
		{
			for (int x = 0; x < xMax; ++x)
			{
				draw(x, y, val);
			}
		}
	}

	void print(const char* title = "<My Canvas>")
	{
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; ++y)
		{
			cout << line[y] << endl;
		}
		cout << endl;
	}
};