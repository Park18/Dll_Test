#include "pch.h"
#include "Foo.h"

using namespace std;

Foo::Foo(int numI, double numD)
{
	this->numI = numI;
	this->numD = numD;
}

int Foo::Bar()
{
	return this->numI;
}

void Foo::Ho(Hello* hello)
{
	this->numI = hello->numI;
	this->numD = hello->numD;
	cout << "member variables are changed !" << endl;
	cout << "numI : " << this->numI << "," << "numD : " << this->numD << endl;
}

Hello Foo::pang()
{
	Hello ret(this->numD, this->numI);
	return ret;
}
