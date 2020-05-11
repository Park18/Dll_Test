#include "pch.h"
#include "Dll.hpp"

DLLEXPORT Foo* CreateFoo(int numI, double numD)
{
	return new Foo(numI, numD);
}

DLLEXPORT int32_t Foo_Bar(Foo* pFoo)
{
	return pFoo->Bar();
}

void Foo_Ho(Foo* pFoo, Hello* hello)
{
	pFoo->Ho(hello);
}

Hello Foo_Pang(Foo* pFoo)
{
	return pFoo->pang();
}

void DeleteFoo(Foo* pFoo)
{
	delete pFoo;
}
