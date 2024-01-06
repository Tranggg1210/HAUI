namespace TamGiac
{
    internal class Program
    {
        static void Main(string[] args)
        {
            float a, b, c;
            try
            {
                do
                {
                    Console.WriteLine("Nhap vao ba canh cua tam giac a,b,c ");
                    Console.Write("a = ");
                    a = float.Parse(Console.ReadLine());
                    Console.Write("b = ");
                    b = float.Parse(Console.ReadLine());
                    Console.Write("c = ");
                    c = float.Parse(Console.ReadLine());
                } while (a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (b + c) <= a || (a + c) <= b);
                float p = (a + b + c) / 2;
                double s = Math.Sqrt(p*(p-a)*(p-b)*(p-c));
                Console.WriteLine("Chu vi va dien tich tam giac la: {0} va {1}",p*2,s);
            }
            catch(FormatException e)
            {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("Sai dinh dang du lieu hoac chua nhap du lieu");
                Console.ResetColor();
            }
        }
    }
}