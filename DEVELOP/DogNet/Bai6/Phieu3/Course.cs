using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu3
{
    internal class Course
    {
        private string courseID;
        private string courseName;
        private int fee;
        private List<Student> li;

        public List<Student> Li {
            get{ return li; }
  
        }

        // contructor
        public Course()
        {
            li = new List<Student>();
        }

        // getter and setter
        public string CourseID
		{ get { return courseID; } set { courseID = value; } }
		public string CourseName
		{ get { return courseName; }  set { courseName = value; } }
        public int Fee
        { get { return fee; } set { fee = value; }  }

        // InputCoure
        public void InputCourse()
        {
            Console.Write("\tCourse id: ");
            courseID = Console.ReadLine();
            Console.Write("\tCourse name: ");
            courseName = Console.ReadLine();
            Console.Write("\tFee: ");
            fee = int.Parse(Console.ReadLine());
            li = new List<Student>();
            int n;
            do
            {
                Console.Write("\tSo luong sinh vien: ");
                n = int.Parse(Console.ReadLine());
            } while (n <= 0);
            for(int i = 0; i < n; i++) {
                Console.WriteLine("\t==== Nhap thong tin sinh vien thu " + (i+1) + " ====");
                Student student = new Student();
                student.InputStudent();
                li.Add(student);
            }
        }

        // Display Course And Students
        public void DisplayCourseAndStudents()
        {
            Console.WriteLine("===== THONG TIN KHOA HOC " + courseName.ToUpper() + " =====");
            Console.WriteLine("CourseID: {0,-15}  CourseName: {1,-15}", courseID, courseName);
            Console.WriteLine("Fee: {0,-15}  Number of Students: {1,-15}", fee, li.Count);
            Console.WriteLine("Danh sach sinh vien: ");
            Console.WriteLine("{0,-15} {1,-15} {2,-15}", "Id", "Name", "Mark");
            foreach (var item in li)
                item.Output();
        }
    }
}
