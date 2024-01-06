using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu_2
{
    internal class Truck:Vehicles
    {
		private int truckLoad;

        // contructor
        public Truck()
        {
            
        }
        public Truck(string id, string maker, string model, int year, double price, int truckload) : base(id, maker, model, year, price) 
        {
            this.truckLoad = truckload;
        }

        // getter and setter
        public int TruckLoad
		{
			get { return truckLoad; }
			set { truckLoad = value; }
		}

        // input
        public override void Input()
        {
            base.Input();
            Console.Write("\tTruckload: ");
            truckLoad = int.Parse(Console.ReadLine());  
        }

        // output
        public override void Output()
        {
            base.Output();
            Console.Write("{0,-16} {1,-15}", " - ", truckLoad != null ? truckLoad : "-");
        }
    }
}
