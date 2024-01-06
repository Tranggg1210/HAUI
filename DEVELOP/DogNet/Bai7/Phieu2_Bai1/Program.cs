namespace Phieu2_Bai1
{
    internal class Program
    {
        private delegate void KetQuaHocTap(double diemTB) ;
        static void Main(string[] args)
        {
            KetQuaHocTap kqht = TinhKQHocTap;
            kqht(8.9);
        }
        private static void TinhKQHocTap(double diemTB)
        {
            if(diemTB < 4.0)
                Console.WriteLine("\nDiem: F");
            else if(diemTB >= 4.0 && diemTB < 5.5)
                Console.WriteLine("\nDiem: D");
            else if(diemTB >= 5.5 && diemTB < 7.0)
                Console.WriteLine("\nDiem: C");
            else if (diemTB >= 7.0 && diemTB < 8.5)
                Console.WriteLine("\nDiem: B");
            else
                Console.WriteLine("\nDiem: A");
        }
    }
}