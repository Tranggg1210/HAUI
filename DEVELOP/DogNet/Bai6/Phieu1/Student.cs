using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu1
{
    internal class Student: Person
    {
        private byte Maths { get; set; } 
        private byte Physics { get; set; }

        // contructor
        public Student()
        {
            
        }
        public Student(int id, string name, string address, byte maths, byte physics):base(id, name, address)
        {
            this.Maths = maths;
            this.Physics = physics;
        }

        public override void Input()
        {
            base.Input();
            Console.Write("\tMaths score: ");
            Maths = byte.Parse(Console.ReadLine());
            Console.Write("\tPhysics score: ");
            Physics = byte.Parse(Console.ReadLine());
        }

        public float Total()
        {
            return Maths + Physics;
        }

        public override void printTitle()
        {
            base.printTitle();
            Console.Write("{0,10} {1,10} {2,10}", "MSCORE", "PSCORE", "TOTAL");
        }
        public override void Output()
        { 
            base.Output();
            Console.Write("{0,10} {1,10} {2,10}", Maths, Physics, Total());
        }
    }
}
