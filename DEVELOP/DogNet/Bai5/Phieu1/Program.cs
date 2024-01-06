using System.Collections;

namespace Phieu1
{
    internal class Program
    {
        static ThiSinh Nhap1TS()
        {
            Console.WriteLine("\n\n===== NHAP THONG TIN THI SINH =====");
            ThiSinh a = new ThiSinh();
            a.Input();
            return a;
        }
        static void OutputDS(ArrayList arr)
        {
            if (arr.Count > 0)
            {
                ((ThiSinh)arr[0]).printTitle(); 
            }

            for (int i = 0; i < arr.Count; i++)
            {
                ((ThiSinh)arr[i]).Output();
            }

        }

        static void printByTongDiem(ArrayList arr)
        {
            if (arr.Count > 0)
            {
                int t, count=0;
                do
                {
                    Console.Write("Nhap tong diem ban muon tim kiem: ");
                    t = int.Parse(Console.ReadLine());
                } while (t < 0) ;
                for(int i = 0; i < arr.Count;i++)
                {
                    if (((ThiSinh)arr[i]).sumScore() >= t)
                    {
                        count++;
                        break;
                    }
                }
                if(count == 0)
                {
                    Console.WriteLine("\nTrong danh sach khong co thi sinh nao co tong diem >= " + t);
                }
                else
                {
                    Console.WriteLine("\n\n===== DANH SACH CAC THI SINH CO TONG DIEM LON HON HOAC BANG " + t + " =====");
                    ((ThiSinh)arr[0]).printTitle();
                    for (int i = 0; i < arr.Count; i++)
                    {
                        if (((ThiSinh)arr[i]).sumScore() >= t)
                        {
                            ((ThiSinh)arr[i]).Output();
                        }
                    }
                }
            }
            else Console.WriteLine("\nDanh sach trong");
        }

        static void printByDiaChi(ArrayList arr)
        {
            if (arr.Count > 0)
            {
                int count = 0;
                string t;
                do
                {
                    Console.Write("Nhap dia chi thi sinh ban muon tim kiem: ");
                    t = Console.ReadLine();
                } while (t == null && t.Trim() == "" );
                for (int i = 0; i < arr.Count; i++)
                {
                    if (((ThiSinh)arr[i]).diaChi.Equals(t, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        break;
                    }
                }
                if (count == 0)
                {
                    Console.WriteLine("\nTrong danh sach khong co thi sinh nao co dia chi o " + t);
                }
                else
                {
                    Console.WriteLine("\n\n===== DANH SACH CAC THI SINH CO DIA CHI O " + t + " =====");
                    ((ThiSinh)arr[0]).printTitle();
                    for (int i = 0; i < arr.Count; i++)
                    {
                        if (((ThiSinh)arr[i]).diaChi.Equals(t, StringComparison.OrdinalIgnoreCase))
                        {
                            ((ThiSinh)arr[i]).Output();
                        }
                    }
                }
            }
            else Console.WriteLine("\nDanh sach trong");
        }

        static void printBySBD(ArrayList arr)
        {
            if (arr.Count > 0)
            {
                int count = 0;
                string t;
                do
                {
                    Console.Write("Nhap so bao danh thi sinh ban muon tim kiem: ");
                    t = Console.ReadLine();
                } while (t == null && t.Trim() == "");
                for (int i = 0; i < arr.Count; i++)
                {
                    if (((ThiSinh)arr[i]).soBaodanh.Equals(t, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        break;
                    }
                }
                if (count == 0)
                {
                    Console.WriteLine("\nTrong danh sach khong co thi sinh nao co so bao danh " + t);
                }
                else
                {
                    Console.WriteLine("\n\n====== THI SINH SO BAO DANH LA {0} ===== ", t);
                    ((ThiSinh)arr[0]).printTitle();
                    for (int i = 0; i < arr.Count; i++)
                    {
                        if (((ThiSinh)arr[i]).soBaodanh.Equals(t, StringComparison.OrdinalIgnoreCase))
                        {
                            ((ThiSinh)arr[i]).Output();
                        }
                    }
                }
            }
            else Console.WriteLine("\nDanh sach trong");
        }

        static void Main(string[] args)
        {
            ArrayList array = new ArrayList();
            int choose;
            do
            {
                Console.WriteLine("\n===== DANH SACH LUA CHON =====");
                Console.WriteLine("1. Nhap thong tin 1 thi sinh");
                Console.WriteLine("2. Hien thi danh sach thi sinh");
                Console.WriteLine("3. Hien thi cac sinh vien theo tong diem");
                Console.WriteLine("4. Hien thi cac sinh vien theo dia chi");
                Console.WriteLine("5. Tim kiem theo so bao danh");
                Console.WriteLine("6. Ket thuc chuong trinh");
                do
                {
                    Console.Write("Nhap lua chon cua ban: ");
                    choose = int.Parse(Console.ReadLine());
                } while (choose <= 0 && choose > 6);

                switch (choose)
                {
                    case 1:
                        {
                            ThiSinh a = Nhap1TS();
                            array.Add(a);
                        }; break;
                    case 2:
                        {
                            Console.WriteLine("\n\n===== DANH SACH THI SINH =====");
                            OutputDS(array);
                        };
                        break;
                    case 3:
                        printByTongDiem(array); break;
                    case 4:
                        printByDiaChi(array); break;
                    case 5:
                        printBySBD(array); break;
                    case 6: return;
                }

            } while (true);
        }
    }
}