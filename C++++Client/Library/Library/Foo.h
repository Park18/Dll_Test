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
	Foo(int numI, double numD);	// 값 형식 변수 인자로 전달
	int Bar();					// 값 형식 멤버 반환
	void Ho(Hello* hello);		// 참조 형식 구조체 인자로 전달
	Hello pang();
};

