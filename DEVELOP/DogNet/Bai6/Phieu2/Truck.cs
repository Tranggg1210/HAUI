using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu2
{
    internal class Truck : Vehicles
    {
        private int truckload;
        public int Truckload
        {
            get { return truckload; }
        }

        // contructor
        public Truck()
        {
            
        }
        public Truck(int truckload, string id, string marker, string model, int year, double price): base(id, marker,model, year, price)
        {
            this.truckload = truckload;
        }

        // Input
        public override void Input()
        {
            base.Input();
            Console.Write("\tTruckload: ");
            truckload = int.Parse(Console.ReadLine());
        }
        public override void Output() { 
            base.Output();
            Console.Write("{0,15} {1,15}", " - ", truckload);
        }
    }
}
