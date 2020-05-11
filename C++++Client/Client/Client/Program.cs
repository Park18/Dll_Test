using System;
using System.Runtime.InteropServices; // DllImport 애트리뷰트

namespace Client
{
    // C#에서 사용할 Hello 구조체, C++ 구조체와 멤버의 자료형만 일치하면 된다.
    [StructLayout(LayoutKind.Sequential)]
    struct Hello
    {
        public Double numD;
        public Int32 numI;
        public Hello(Double numD, Int32 numI)
        {
            this.numD = numD;
            this.numI = numI;
        }
    }

    class Program
    {
        /**
         * C++에서 작성한 전역함수의 C# Wrapper 함수들
         * 구조체 포인터가 존재하는 자리에 IntPtr형식을 사용하면 된다.
         * C++ dll의 함수명과 아래의 함수명은 같아야 한다.
         * 다른 함수명을 사용하고 싶은 경우 애트리뷰트에 옵션을 주면 되지만 다루지 않는다.
         */

        [DllImport("Library.dll")]
        extern public static IntPtr CreateFoo(Int32 numI, Double numD); // C++에서 Foo* 형식은 IntPtr 사용
        [DllImport("Library.dll")]
        extern public static int Foo_Bar(IntPtr pFoo);
        [DllImport("Library.dll")]
        extern public static void Foo_Ho(IntPtr pFoo, ref Hello hello); // C++ 에서 Hello* 형식은 ref Hello를 사용
        [DllImport("Library.dll")]
        extern public static Hello Foo_Pang(IntPtr pFoo);
        [DllImport("Library.dll")]
        extern public static void DeleteFoo(IntPtr pFoo);

        static void Main(string[] args)
        {
            IntPtr Foo = CreateFoo(10, 12.0);

            int ret = Foo_Bar(Foo);
            Console.WriteLine($"[Foo_Bar] ret={ret}");

            Hello hello = new Hello(32.0, 31);
            Foo_Ho(Foo, ref hello);

            Hello hello2 = Foo_Pang(Foo);
            Console.WriteLine($"[Foo_Pang] hello2.numI={hello2.numI}, hello2.numD={hello2.numD}");

            DeleteFoo(Foo);
        }
    }
}
