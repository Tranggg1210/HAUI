namespace Bai3_Phieu2
{
    internal class Program
    {
        public struct SV {
            private int id;
            private string name;
            private string gender;
            private int age;
            private float mathScores;
            private float pointChemical;
            private float pointPhysical;

            public void input()
            {
                try
                {
                    id += 1;
                    Console.Write("\tHo ten: ");
                    name = Console.ReadLine();
                    Console.Write("\tGioi tinh: ");
                    gender = Console.ReadLine();
                    Console.Write("\tTuoi: ");
                    age = int.Parse(Console.ReadLine());
                    Console.Write("\tDiem toan: ");
                    mathScores = float.Parse(Console.ReadLine());
                    Console.Write("\tDiem hoa: ");
                    pointChemical = float.Parse(Console.ReadLine());
                    Console.Write("Diem ly: ");
                    pointPhysical = float.Parse(Console.ReadLine());
                }catch (FormatException) {
                    Console.BackgroundColor = ConsoleColor.Red;
                    Console.WriteLine("Sai dinh dang du lieu hoac chua nhap du lieu");
                    Console.ResetColor();
                }
            }
        }

        //  1. Them sinh vien
        internal static void AddMembers(List<SV> list)
        {
            SV s = new SV();
            s.input();
            list.Add(s);
        }

        // 2. Cap nhap thong tin sinh vien

        static void Main(string[] args)
        {
            List<SV> listSV = new List<SV>();
            int n;
            do
            {
                Console.WriteLine("============ MENU ============");
                Console.WriteLine("1.Them sinh vien");
                Console.WriteLine("2.Cap nhap thong tin sinh vien");
                Console.WriteLine("3.Xoa sinh vien boi ID");
                Console.WriteLine("4.Tim kiem sinh vien theo ten");
                Console.WriteLine("5.Sap xep sinh vien theo diem trung binh");
                Console.WriteLine("6.Sap xep sinh vien theo ten");
                Console.WriteLine("7.Hien thi danh sach sinh vien");
                Console.WriteLine("8.Ghi danh sach sinh vien vao file \"student.txt\"");
                Console.WriteLine("9.Thoat");
                do
                {
                    Console.WriteLine("Nhap lua chon cua ban: ");
                    n = int.Parse(Console.ReadLine());
                }while (n <= 0 || n > 9);
                switch(n)
                {
                    case 1:
                        AddMembers(listSV);
                        break;
                }
            }while(n != 9);
        }
    }
}