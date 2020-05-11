#pragma once
#include "Foo.h"

/**
 * c++ class를 c#형태로 marshalling 하기는 복잡함, 따라서
 * 첫 번째 인자로 클래스에 대한 포인터를 가지는 전역함수의 형태로 export
 * extern "C" : 함수 mangling 차단
 * __declspec(dllexpport) : dll로 export
 */

#define DLLEXPORT __declspec(dllexport)

extern "C"
{
    DLLEXPORT Foo* CreateFoo(int numI, double numD);
    DLLEXPORT int32_t Foo_Bar(Foo* pFoo);
    DLLEXPORT void Foo_Ho(Foo* pFoo, Hello* hello);
    DLLEXPORT Hello Foo_Pang(Foo* pFoo);
    DLLEXPORT void DeleteFoo(Foo* pFoo);
}
