using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu1
{
    internal class Person
    {
        protected int id;
        protected string name;
        protected string address;

        // getter
        public int ID
        {
            get { return id; }
        }

        public string Name
        { get { return name; } }

        public string Address
        { get { return address; } }

        // constructor
        public Person()
        {
            
        }
        public Person( int id, string name, string address)
        {
            this.id = id;
            this.name = name;
            this.address = address;
        }
        public virtual void Input()
        {
            Console.Write("\tID: ");
            id = int.Parse(Console.ReadLine());
            Console.Write("\tName: ");
            name = Console.ReadLine();
            Console.Write("\tAddress: ");
            address = Console.ReadLine();
        }

        public virtual void printTitle()
        {
            Console.Write("\n{0,8} {1, 15} {2,15}", "ID", "NAME", "ADDRESS");
        }
        public virtual void Output()
        {
            Console.Write("\n{0,8} {1, 15} {2,15}", id, name, address);
        }
    }
}
