using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu1_Bai3
{
    internal class Student
    {
		private string _id;
		private string _name;
		private int _mark;

        // contructor
        public Student()
        {
            
        }

        public Student(string id, string name, int mark)
        {
            this._id = id;
            this._name = name;
            this._mark = mark;
        }

        public Student(string id)
        {
           this._id=id;
        }

        //getter and setter
        public string ID
		{
			get { return _id; }
			set { _id = value; }
		}
        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }
        public int Mark
        {
            get { return _mark; }
            set { _mark = value; }
        }

        // tinh scholarship
        public int scholarship()
        {
            if (_mark > 8)
            {
                return 500;
            }
            else if (_mark <= 8 && _mark >= 7) return 300;
            return 0;
                
        }

        // ToString
        public override string ToString()
        {
            return (
                "ID: " + _id +
                "\nName: " + _name +
                "\nMark: " + _mark +
                "\nScholarship: " + scholarship());
        }
    }
}
