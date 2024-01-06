using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu1_Bai1
{
    internal class Person
    {
        protected string _id;
        protected string _name;
        protected int _age;
        protected string _email;
        protected string _address;

        // constructor
        public Person(string id, string name, int age, string email, string address)
        {
            this._id = id;
            this._name = name;
            this._age = age;
            this._email = email;
            this._address = address;
        }
        public Person()
        {

        }

        // getter and setter
        public string Id
        {
            get { return _id; }
            set { _id = value; }
        }

        public string Name
        { 
            get { return _name; } 
            set { _name = value; } 
        }
        public int Age { 
            get { return _age; } 
            set { _age = value; } 
        }
        public string Email { 
            get { return _email; } 
            set { _email = value; } 
        }
        public string Address { 
            get { return _address; } 
            set { _address = value; } 
        }

        // method
        public void CheckAge()
        {
            if (_age >= 18)
                Console.WriteLine("\nBan du tuoi bau cu");
            else Console.WriteLine("\nBan con nho");
        }

        public void Input()
        {
            Console.WriteLine("===== NHAP THONG TIN NGUOI DUNG =====");
            Console.Write("\tID: ");
            _id = Console.ReadLine();
            Console.Write("\tName: ");
            _name = Console.ReadLine();
            Console.Write("\tAge: ");
            _age = int.Parse(Console.ReadLine());
            Console.Write("\tEmail: ");
            _email = Console.ReadLine();
            Console.Write("\tAddress: ");
            _address = Console.ReadLine();
        }

        public void Output()
        {
            Console.WriteLine("===== THONG TIN NGUOI DUNG =====");
            Console.Write(
                "ID: " + _id
                + "\nName: " + _name
                + "\nAge: " + _age
                +"\nEmail: " + _email
                + "\nAddress: " + _address
                );
            ;
        }
    }
}
