#pragma once
#include "Foo.h"

/**
 * c++ class�� c#���·� marshalling �ϱ�� ������, ����
 * ù ��° ���ڷ� Ŭ������ ���� �����͸� ������ �����Լ��� ���·� export
 * extern "C" : �Լ� mangling ����
 * __declspec(dllexpport) : dll�� export
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
