#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

class Complex 
{
	double real;
	double imag;
	
public:
	void setComplex(double r, double i)
	{
		real = r;
		imag = i;
	}

	void readComplex(const char* msg = " ���Ҽ� = ");
	void printComplex(const char* msg = " ���Ҽ� = ");
	void addComplex(Complex a, Complex b);
};