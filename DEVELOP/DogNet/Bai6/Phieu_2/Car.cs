using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu_2
{
    internal class Car: Vehicles
    {
		private string color;

        // contructor
        public Car()
        {
            
        }
        public Car(string id, string maker, string model, int year, double price, string color ):base(id, maker, model, year, price)
        {
            this.color = color;
        }

        // getter and setter
        public string Color
		{
			get { return color; }
			set { color = value; }
		}

        // input
        public override void Input()
        {
            base.Input();
            Console.Write("\tColor: ");
            color = Console.ReadLine();
        }

        // output
        public override void Output()
        {
            base.Output();
            Console.Write("{0,-16} {1,-15}", string.IsNullOrEmpty(color) ? "-" : color, "-");
        }

    }
}
