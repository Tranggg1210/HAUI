using System.Collections;
using System.ComponentModel.Design;

namespace Phieu1
{
    internal class Program
    {
        static void Output(ArrayList listStudent)
        {
           if(listStudent.Count <= 0)
            {
                Console.WriteLine("\nDanh sach hien dang trong!!!");
            }
            else
            {
                Console.WriteLine("\n\n==== DANH SACH THONG TIN SINH VIEN");
                ((Student)listStudent[0]).printTitle();
                foreach (Student student in listStudent)
                    student.Output();
            }
        }
        static void searchByID(ArrayList list)
        {
            int search, count = 0;
            do
            {
                Console.Write("\nNhap ID can tim kiem: ");
                search = int.Parse(Console.ReadLine());
            }while (search <= 0);
            foreach (Student student in list)
            {
                if (student.ID == search)
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
                Console.WriteLine("\n\nKhong co sinh vien co ID nhu vay trong danh sach");
            else
            {
                Console.WriteLine("\n\n==== SINH VIEN CO ID NHU VAY TRONG DANH SACH LA:");
                ((Student)list[0]).printTitle();
                foreach (Student student in list)
                {
                    if (student.ID == search)
                    {
                        student.Output();
                    }
                }
            }
                   
        }
        static void searchByAdress(ArrayList list)
        {
            string search;
            int count = 0;
            do
            {
                Console.Write("\nNhap ADDRESS can tim kiem: ");
                search = Console.ReadLine();
            } while (search == null && search.Trim() == "") ;
            foreach (Student student in list)
            {
                if (student.Address.Equals(search, StringComparison.OrdinalIgnoreCase))
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
                Console.WriteLine("\n\nKhong co sinh vien co ADDRESS nhu vay trong danh sach");
            else
            {
                Console.WriteLine("\n\n==== NHUNG SINH VIEN CO ADDRESS NHU VAY TRONG DANH SACH LA:");
                ((Student)list[0]).printTitle();
                foreach (Student student in list)
                {

                    if (student.Address.Equals(search, StringComparison.OrdinalIgnoreCase))
                    {
                        student.Output();
                    }
                }
            }

        }

        static void deleteByID(ArrayList list)
        {
            int search, count = 0;
            do
            {
                Console.Write("\nNhap ID can xoa: ");
                search = int.Parse(Console.ReadLine());
            } while (search <= 0);
            foreach (Student student in list)
            {
                if (student.ID == search)
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
                Console.WriteLine("\n\nKhong co sinh vien co ID nhu vay trong danh sach");
            else
            {
                Console.WriteLine("\n\nSINH VIEN CO " + search + " DA DUOC XOA RA KHOI DANH SACH");
                Console.WriteLine("==== DANH SACH SINH VIEN SAU KHI XOA SINH VIEN CO {0} LA:", search);
                ((Student)list[0]).printTitle();
                list.Remove(search);
            }

        }
        static void Main(string[] args)
        {
            int choose;
            ArrayList listStudent = new ArrayList();
            do
            {
                Console.WriteLine("\n==== MENU ====");
                Console.WriteLine("1. Them mot sinh vien");
                Console.WriteLine("2. Hien thi danh sach sinh vien");
                Console.WriteLine("3. Tim kiem sinh vien theo ID");
                Console.WriteLine("4.Tim kiem sinh vien theo address");
                Console.WriteLine("5. Xoa mot sinh vien theo id");
                Console.WriteLine("6. Ket thuc chuong trinh");
                do
                {
                    Console.Write("Nhap lua chon cua ban: ");
                    choose = int.Parse(Console.ReadLine());
                }while (choose <= 0 || choose >= 7);

                switch (choose)
                {
                    case 1:
                        {
                            Student student = new Student();
                            bool isCheckStudent = false;
                                Console.WriteLine("\n\n==== NHAP THONG TIN SINH VIEN BAN MUON THEM: ");
                                student.Input();
                                if(listStudent.Count > 0)
                                {
                                    foreach(Student item in  listStudent)
                                    {
                                        if(item.ID == student.ID)
                                        {
                                            Console.WriteLine("\nSinh vien bi trung ma ID");
                                            isCheckStudent = true;
                                        break;
                                        }    
                                    }    
                                }    
                        
                            if(!isCheckStudent) listStudent.Add(student);
                        }
                        break;
                    case 2:
                        {
                            Output(listStudent);
                        };
                        break;
                    case 3:
                        {
                            searchByID(listStudent);
                        };
                        break;
                    case 4:
                        {
                            searchByAdress(listStudent);
                        };
                        break;
                    case 5:
                        {
                            deleteByID(listStudent);
                        };
                        break;
                    case 6:
                        {
                            return;

                        };
                }

            } while (true);
        }
    }
}