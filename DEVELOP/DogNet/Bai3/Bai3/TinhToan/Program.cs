namespace TinhToan
{
    internal class Program
    {
        public static double TinhToan(float a, float b, char c)
        {
            switch(c)
            {
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': 
                    if(b != 0) return a / b;
                    else throw new DivideByZeroException("Chia cho 0 la khong hop le");
                default: return -999999999999999;
            }
        }
        static void Main(string[] args)
        {
            try
            {
                float a, b;
                Console.Write("Nhap a: ");
                a = float.Parse(Console.ReadLine());
                Console.Write("Nhap b: ");
                b = float.Parse(Console.ReadLine());
                char c;
                do
                {
                    Console.Write("Nhap c: ");
                    c = char.Parse(Console.ReadLine());
                } while (c != '+' && c != '-' && c != '*' && c != '/');
                double d;
                d = TinhToan(a, b, c);
                if (c == '+') Console.WriteLine("{0} + {1} = {2}",a,b, d);
            } catch (FormatException) {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("Ban chua nhap du lieu hoac nhap sai dinh dang du lieu");
                Console.ResetColor();
            } catch(DivideByZeroException e)
            {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine(e.Message);
                Console.ResetColor();
            }
        }
    }
}