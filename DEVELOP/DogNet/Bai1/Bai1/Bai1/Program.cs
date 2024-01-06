using System;

namespace Bai1
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
             *   Bài tập 1
                 Viết chương trình nhập vào 1 số nguyên n. Cho biết (in ra màn hình
                 console):
                 a) n là số chẵn hay số lẻ?
                 b) n là số âm hay số không âm?
             */
             Console.Write("Nhap n: ");
             int n = int.Parse(Console.ReadLine());
             if(n % 2 == 0) {
                 Console.WriteLine("{0} la so chan", n);
             }else { Console.WriteLine("{0} la so le", n); }
             if (n < 0)
             {
                 Console.WriteLine("{0} la so am", n);
             }
             else { Console.WriteLine("{0} la so khong am", n); }


            /*
             *  Bài tập 2
                Viết chương trình nhập vào 2 số thực dương chỉ chiều dài và chiều rộng của
                hình chữ nhật. In ra màn hình chu vi và diện tích của hình chữ nhật đó.
             */

            float d, r;

             do
             {
                 Console.Write("Nhap chieu dai cua hinh chu nhat: ");
                 d = float.Parse(Console.ReadLine());
             }while (d < 1);
             do
             {
                 Console.Write("Nhap chieu rong cua hinh chu nhat: ");
                 r = float.Parse(Console.ReadLine());
             } while (r < 1);
             Console.WriteLine("Chu vi hinh chu nhat la: {0:F3}", (r+d)*2);
             Console.WriteLine("Dien tich cua hinh chu nhat la: {0:F3}", r * d);

            /*
             *  Bài tập 3
                a. Viết chương trình giải phương trình bậc nhất: ax + b = 0
                b. Viết chương trình giải phương trình bậc hai: ax2 + bx + c = 0
             */


            float a1, b1;
            Console.WriteLine("Nhap cac thong so cua phuong trinh bac nhat:");
            Console.Write("Nhap a: ");
            a1 = float.Parse(Console.ReadLine());
            Console.Write("Nhap b: ");
            b1 = float.Parse(Console.ReadLine());
            if (a1 == 0)
            {
                if (b1 == 0) Console.WriteLine("Phuong trinh bac nhat co vo so nghiem");
                else Console.WriteLine("Phuong trinh bac nhat vo nghiem");
            } else Console.WriteLine("Phuong trinh bac nhat co nghiem la: {0:F2}", ((-b1)/a1));  

            float a,b, c;
            Console.WriteLine("Nhap cac thong so cua phuong trinh bac hai:");
            Console.Write("Nhap a: ");
            a = float.Parse(Console.ReadLine());
            Console.Write("Nhap b: ");
            b = float.Parse(Console.ReadLine());
            Console.Write("Nhap c: ");
            c = float.Parse(Console.ReadLine());

            if(a == 0)
            {
                if (b == 0)
                {
                    if (c == 0) { Console.WriteLine("Phuong trinh bac hai co vo so nghiem"); }
                    else { Console.WriteLine("Phuong trinh bac hai vo nghiem"); }
                }
                else { Console.WriteLine("Phuong trinh bac nhat co nghiem la: {0:F2}", (-c) / b); }   
            }  else
            {
                float denta = b * b - 4 * a * c;
                if(denta < 0) { Console.WriteLine("Phuong trinh bac hai vo nghiem"); }
                else if(denta == 0) { Console.WriteLine("Phuong trinh co nghiem kep: {0:F2}", (-b)/(2*a)); }
                else { 
                    double x1 = (((-b) + Math.Sqrt(denta)) / (2*a));
                    double x2 = (((-b) - Math.Sqrt(denta)) / (2*a));
                    Console.WriteLine("Phuong trinh bac hai co nghiem kep: x1 = {0:F2} va x2 = {1:F2}",x1,x2); 
                }
            } 


            /*
             *  Viết chương trình nhập bậc lương (BacLuong), ngày công (NgayCong), phụ
                cấp (PhuCap).
                Tính tiền thực lĩnh (TienLinh) theo công thức sau:
                TienLinh = BacLuong * 1.490.000 * NCTL + PhuCap, trong đó:
                - NCTL = NgayCong nếu NgayCong < 25
                - NCTL = 25 + (NgayCong – 25) * 2 nếu NgayCong >= 25
             */

             int BacLuong, NgayCong, PhuCap;
             int NCTL;
             do
             {
                 Console.Write("Nhap bac luong: ");
                 BacLuong = int.Parse(Console.ReadLine());
             } while (BacLuong < 1);
             do
             {
                 Console.Write("Nhap ngay cong: ");
                 NgayCong = int.Parse(Console.ReadLine());
             } while (NgayCong < 1);
             do
             {
                 Console.Write("Nhap phu cap: ");
                 PhuCap = int.Parse(Console.ReadLine());
             } while (PhuCap < 1);
             if (NgayCong < 25)
                 NCTL = NgayCong;
             else NCTL = 25 + (NgayCong - 25)*2;
             decimal TienLinh = BacLuong * 1490000 * NCTL + PhuCap;
             Console.WriteLine("Tien luong la: {0} * 1490000 * {1} + {2} = {3}", BacLuong, NCTL, PhuCap, TienLinh);

            /*
             *  Bài tập 5
                Viết chương trình nhập vào một số nguyên nằm trong khoảng 1 đến 7, in ra
                thứ trong tuần tương ứng với số nhập vào. Trong đó:
                1: chủ nhật; 2: thứ hai; 3: thứ ba; 4: thứ tư; 5: thứ năm; 6: thứ sáu; 7: thứ 7.
             */

            int n1;
            do
            {
                Console.Write("Nhap 1 <= n <= 7: ");
                n1 = int.Parse(Console.ReadLine());
            } while (n1 < 1 || n1 > 6);
            switch (n1)
            {
                case 1: Console.WriteLine("Chu nhat"); break;
                case 2: Console.WriteLine("Thu hai"); break;
                case 3: Console.WriteLine("Thu ba"); break;
                case 4: Console.WriteLine("Thu tu"); break;
                case 5: Console.WriteLine("Thu nam"); break;
                case 6: Console.WriteLine("Thu sau"); break;
                case 7: Console.WriteLine("Thu bay"); break;
            }

            /*
             *  Bài tập 6
                Viết chương trình nhập vào một số nguyên cho đến khi nhận được số nguyên
                dương thì dừng.
             */
            int n2;
            Console.Write("Nhap n: ");
            n2 = int.Parse(Console.ReadLine());
            if(n2 < 2) {
                Console.WriteLine("So {0} khong phai so nguyen to", n2);
            }
            else
            {
                for(int i = 2; i <= Math.Sqrt(n2); i++)
                {
                    if(n2 % i == 0)
                    {
                        Console.WriteLine("So {0} khong phai so nguyen to", n2);
                        return;
                    }    
                }
                Console.WriteLine("So {0} la so nguyen to", n2);
            }

            /*
             *  Bài tập 8
                Viết chương trình nhập vào một số nguyên dương n. In ra màn hình các số từ
                1 đến n, bỏ qua các số chia hết cho 5.
             */
            int n3;
            Console.Write("Nhap n: ");
            n3 = int.Parse(Console.ReadLine());
            for(int i = 1; i <= n3; i++)
            {
                if (i % 5 == 0)
                {
                    continue;
                }
                else Console.Write(i + "    ");
            }    
        }
    }
}
