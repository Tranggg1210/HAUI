using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu2
{
    internal class Car : Vehicles
    {
        private string color;
        public string Color
        {
            get { return color; }
        }
        public Car()
        {
            
        }

        public Car(string id, string maker, string model, int year, double price, string color) : base(id, maker, model, year, price)
        {
            this.color = color;
        }

        public override void Input()
        {
            base.Input();
            Console.Write("\tColor: ");
            this.color = Console.ReadLine();
        }

        public override void Output()
        {
            base.Output();
            Console.Write("{0,15} {1,15}", color, " - ");
        }
    }
}
