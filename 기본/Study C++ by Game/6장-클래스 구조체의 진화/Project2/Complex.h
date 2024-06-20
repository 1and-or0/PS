#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

struct Complex {
	double real;
	double imag;
};

inline void setComplex(Complex& c, double r, double i)
{
	c.real = r;
	c.imag = i;
}

extern Complex readComplex(const char* msg = "���Ҽ� = ");

extern void printComplex(Complex c, const char* msg = "���Ҽ� = ");

extern Complex addComplex(Complex a, Complex b);