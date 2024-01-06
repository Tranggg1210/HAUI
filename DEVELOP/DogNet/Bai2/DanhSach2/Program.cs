using System;

namespace DanhSach2
{
    class Program
    {
        static void output(List<string> list)
        {
            foreach(string item in list)
            {
                Console.WriteLine(item);
            }
        }
        static void Main(string[] args)
        {
            List<string> ThanhPho = new List<string>();
            int n = 0;
            do
            {
                Console.Write("Nhap ten thanh pho thu {0} : ", n);
                ThanhPho.Add(Console.ReadLine());
                n++;
            }while(n < 5);
            Console.WriteLine("\nDanh sach thanh pho vua nhap la: ");
            output(ThanhPho);
            ThanhPho.Sort();
            Console.WriteLine("\nDanh sach thanh pho sau khi sap xep tang dan la: ");
            output(ThanhPho);
            int count = 0;
            foreach(string item in ThanhPho){
                if (item.Equals("Ha Noi"))
                {
                    ThanhPho.Remove(item);
                    break;

                }
                else count++;
            }
            if(count == ThanhPho.First().Length)
            {
                Console.WriteLine("Thanh pho Ha Noi khong co ten trong mang Thanh Pho");
            }
            else
            {
                Console.WriteLine("\nMang sau khi xoa ten thanh pho Ha Noi: ");
                output(ThanhPho);
            }
        }
    }
}