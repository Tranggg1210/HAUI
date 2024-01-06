using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu3
{
    internal class Student
    {
		private int studentID;
		private string name;
		private string mark;


        // contructor 
        public Student()
        {
            
        }

        public Student(int id, string name, string mark)
        {
            this.studentID = id;
            this.name = name;
            this.mark = mark;
        }

        // getter and setter
        public int StudnetID
        {
            get { return studentID; }
            set { studentID = value; }
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public string Mark
		{
			get { return mark; }
			set { mark = value; }
		}

        // toString
        public override string ToString()
        {
            return (
                studentID + "; " + name + "; " + mark
                );
        }

        // input
        public void InputStudent()
        {
            Console.Write("\tId: ");
            studentID = int.Parse(Console.ReadLine());
            Console.Write("\tName: ");
            name = Console.ReadLine();
            Console.Write("\tMark: ");
            mark = Console.ReadLine();
        }

        // output
        public void Output()
        {
            Console.Write("\n{0,-15} {1,-15} {2,-15}", studentID, name , mark);
        }
	}
}
