using System;
namespace Bai4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap ho va ten hoc sinh: ");
            string hoVaTen = Console.ReadLine();
            float diemTK;
            do
            {
                Console.Write("Nhap diem tong ket: ");
                diemTK = float.Parse(Console.ReadLine());
            } while (diemTK < 0 || diemTK > 10);
            Console.WriteLine("Ho va ten: " + hoVaTen.ToUpper());
            if(diemTK >= 8)
            {
                Console.WriteLine("Diem tong ket loai: Gioi");
            }  else if(diemTK >= 6.5)
            {
                Console.WriteLine("Diem tong ket loai: Kha");
            }else if(diemTK >= 5)
            {
                Console.WriteLine("Diem tong ket loai: Trung binh");
            }
            else Console.WriteLine("Diem tong ket loai: Yeu");
        }
    }
}

