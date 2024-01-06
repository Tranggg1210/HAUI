using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu1
{
    internal class ThiSinh
    {
        public string soBaodanh { get; set; }
        public string hoTen { get; set; }
        public string diaChi { get; set; }
        public float diemToan { get; set; }
        public float diemLy { get; set; }
        public float diemHoa { get; set; }
        public float diemUT { get; set;}

        // tong diem
        public double sumScore()
        {
            return diemHoa + diemToan + diemLy + diemUT;
        }

        // input
        public void Input()
        {
            Console.Write("\tSo bao danh: ");
            soBaodanh = Console.ReadLine();
            Console.Write("\tHo ten: ");
            hoTen = Console.ReadLine();
            Console.Write("\tDia chi: ");
            diaChi = Console.ReadLine();
            Console.Write("\tDiem toan: ");
            diemToan = float.Parse(Console.ReadLine());
            Console.Write("\tDiem ly: ");
            diemLy = float.Parse(Console.ReadLine());
            Console.Write("\tDiem hoa: ");
            diemHoa = float.Parse(Console.ReadLine());
            Console.Write("\tDiem uu tien: ");
            diemUT = float.Parse(Console.ReadLine());
        }

        // output
        public void Output()
        {
            Console.Write("\n{0,8} {1,15} {2,15} {3,10} {4,10} {5,10} {6,10} {7,10}", soBaodanh, hoTen, diaChi, diemToan, diemLy, diemHoa, diemUT, sumScore() );
        }

        // print title
        public void printTitle()
        {
            Console.Write("{0,8} {1,15} {2,15} {3,10} {4,10} {5,10} {6,10} {7,10}", "So BD", "Ho Ten", "Dia Chi", "Diem Toan", "Diem Ly", "Diem Hoa", "Diem UT", "Tong Diem");
        }
    }
}
