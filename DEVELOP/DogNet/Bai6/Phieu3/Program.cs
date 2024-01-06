using System.Xml.Serialization;

namespace Phieu3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int choose;
                List<Course> list = new List<Course>();
                do
                {
                    Console.WriteLine("\n===============================================");
                    Console.WriteLine("1. Them mot khoa hoc");
                    Console.WriteLine("2. Hien thi cac khoa hoc");
                    Console.WriteLine("3. Tim kiem khoa hoc");
                    Console.WriteLine("4. Tim kiem sinh vien");
                    Console.WriteLine("5. Xoa mot khoa hoc");
                    Console.WriteLine("6. Ket thuc");
                    do
                    {
                        Console.Write("Nhap lua chon cua ban: ");
                        choose = int.Parse(Console.ReadLine());
                    }while(choose <= 0 || choose > 6);

                    switch(choose)
                    {
                        case 1: {
                                Console.WriteLine("\n===== NHAP THONG TIN KHOA HOC =====");
                                Course course = new Course();
                                course.InputCourse();
                                list.Add(course);
                            }; break;
                        case 2: {
                                hienThi(list);
                            }; break;
                        case 3: {
                                searchByCourseID(list);
                        }; break;
                        case 4: {
                                searchByStudentID(list);
                        }; break;
                        case 5: { deleteByCourseID(list); }; break;
                        case 6: return;
                    }
                } while (true);
            }catch(FormatException e)
            {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("\n===> Sai dinh dang du lieu!!!");
                Console.ResetColor();
            }
        }
        private static void hienThi(List<Course> list)
        {
            if (list.Count > 0)
            {
                foreach(var item in list)
                {
                    item.DisplayCourseAndStudents();
                    Console.WriteLine("\n=========================================");
                }
            }else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }

        private static void searchByCourseID(List<Course> list)
        {
            if (list.Count > 0)
            {
                int count = 0;
                string id;
                do
                {
                    Console.Write("\nNhap coureID can tim: ");
                    id = Console.ReadLine();
                } while (string.IsNullOrEmpty(id));
                foreach(var item in list)
                {
                    if(item.CourseID.Equals(id, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        break;
                    }
                }
                if(count == 0)
                    Console.WriteLine("\n===> Khong co courseID can tim trong danh sach");
                else
                {
                    Console.WriteLine("\n====== THONG TIN KHOA HOC CO COURSEID LA {0} ======", id);
                    foreach (var item in list)
                    {
                        if (item.CourseID.Equals(id, StringComparison.OrdinalIgnoreCase))
                        {
                            item.DisplayCourseAndStudents();
                        }
                    }
                }
            }
            else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }

        private static void searchByStudentID(List<Course> list)
        {
            if (list.Count > 0)
            {
                int count = 0;
                int id;
                do
                {
                    Console.Write("\nNhap studentID can tim: ");
                    id = int.Parse(Console.ReadLine());
                } while (id == null);
                foreach (var course in list)
                {
                    Student foundStudent = course.Li.Find(s => s.StudnetID == id);
                    if (foundStudent != null)
                    {
                        count++;
                        break;
                    }
                }

                if (count == 0)
                    Console.WriteLine("\n===> Khong co studentID can tim trong danh sach");
                else
                {
                    Console.WriteLine("\n====== THONG TIN KHOA HOC CO STUDENTID LA {0} ======", id);
                    Console.Write("{0,-15} {1,-15} {2,-15} {3,-15} {4,-15} {5,-15}", "ID", "Name", "Mark", "CourseID", "CourseName", "Fee");
                    foreach (var item in list)
                    {
                        Student foundStudent = item.Li.Find(s => s.StudnetID == id);

                        if (foundStudent != null)
                        {
                            foundStudent.Output();
                            Console.Write("{0,-15} {1,-15} {2,-15}", item.CourseID, item.CourseName, item.Fee );
                        }
                    }
                }
            }
            else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }

        private static void deleteByCourseID(List<Course> list)
        {
            if (list.Count > 0)
            {
                int count = 0;
                string id;
                do
                {
                    Console.Write("\nNhap coureID can xoa: ");
                    id = Console.ReadLine();
                } while (string.IsNullOrEmpty(id));
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    if (list[i].CourseID.Equals(id, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        list.RemoveAt(i);
                    }
                }
                if (count == 0)
                    Console.WriteLine("\n===> Khong co courseID can xoa trong danh sach");
                else
                {
                    Console.WriteLine("\n====== DANH SACH KHOA HOC SAU KHI XOA LA ======");
                    hienThi(list);
                }
            }
            else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }
    }
}