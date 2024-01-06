namespace Bai3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hay nhap vao 2 so");
            int a, b;
            Console.Write("a = ");
            a = int.Parse(Console.ReadLine());
            Console.Write("b = ");
            b = int.Parse(Console.ReadLine());
            Console.WriteLine("{0} + {1} = {2}", a,b, (a+b));
        }
    }
}