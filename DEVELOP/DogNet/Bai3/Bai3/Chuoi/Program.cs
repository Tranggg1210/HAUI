namespace Chuoi
{
    internal class Program
    {
        public static bool IsSymmetry(string s)
        {
            string a = new string(s.Reverse().ToArray());
            if(s == a)
                return true;
            return false;
        }
        static void Main(string[] args)
        {
            string s;
            do
            {
                Console.Write("Nhap chuoi khong rong: ");
                s = Console.ReadLine();
            } while (s.Trim() == "");
            if (IsSymmetry(s))
                Console.WriteLine("Day la chuoi doi xung");
            else Console.WriteLine("Day KHONG PHAI la chuoi doi xung");
        }
    }
}