#pragma once
#include <iostream>

struct Hello {
	double numD;
	int numI;
	Hello(double numD, int numI) : numD(numD), numI(numI) {}
};

class Foo
{
private:
	int numI;
	double numD;

public:
	Foo(int numI, double numD);	// �� ���� ���� ���ڷ� ����
	int Bar();					// �� ���� ��� ��ȯ
	void Ho(Hello* hello);		// ���� ���� ����ü ���ڷ� ����
	Hello pang();
};

