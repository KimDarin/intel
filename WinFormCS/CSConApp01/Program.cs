using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSConApp01
{
    internal class Program
    {
        static void Main(string[] args)     //주 진입점
        {
            Test test = new Test();
            test.Main();   
        }
    }

    class Test
    {
        void func1()
        {
            Console.WriteLine("long   type의 크기 " + sizeof(long) + "byte 범위 " + long.MinValue + "," + long.MaxValue);
            Console.WriteLine("float  type의 크기 " + sizeof(float) + "byte 범위 " + float.MinValue + "," + float.MaxValue);
            Console.WriteLine("double type의 크기 " + sizeof(double) + "byte 범위 " + double.MinValue + "," + double.MaxValue);
        }
        void func2()
        {
            char a = 'A';
            Console.WriteLine("char a     = " + a);
            Console.WriteLine("char a + 1 = " + (a + 1));
            Console.WriteLine("char a + 2 = " + (a + 2));
        }
        void func3()
        {
            var a = 20;        //string type
            Console.WriteLine($"   var a = {a}");
            a = 10;
            Console.WriteLine($"   var a = {a}");
            Object o = a;
            Console.WriteLine($"Object o = {o}");
            o = "문자열도 되나요?";
            Console.WriteLine($"Object o = {o}");
            string s = (string)o;
            Console.WriteLine($"string s = {s}");
        }
        void func4()
        {
            char[] carr = { '안', '녕', '?', 'ㅋ', 'ㅋ' };
            for (int i = 0; i < carr.Length; i++)
            {
                Console.Write(carr[i]);
            }
            Console.WriteLine("");
            string s = new string(carr); Console.WriteLine(s);  //new는 string class의 생성자
            s = new string(carr, 1, 2);  Console.WriteLine(s);
            s.
        }
        public void Main()     
        {
            //Console.WriteLine("      int type의 크기 " + sizeof(int) + "byte 범위 " + int.MinValue + "," + int.MaxValue);
            //Console.WriteLine("표준  int type의 크기 {0}byte, 범위 {1}, {2}", sizeof(int), int.MinValue, int.MaxValue);
            //Console.WriteLine($"보간 int type의 크기 {sizeof(int)}byte, 범위 {int.MinValue}, {int.MaxValue} ");
            //func1(); func2(); 
            func4();
        }
    };
}
