using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu_2
{
    internal class Vehicles : IVehicle
    {
        private string id;
        private string maker;
        private string model;
        private int year;
        private double price;

        // contructor
        public Vehicles()
        {
            
        }
        public Vehicles( string id, string maker, string model, int year, double price)
        {
            this.id = id;
            this.maker = maker;
            this.model = model;
            this.year = year;
            this.price = price;
        }

        // getter and setter
        public string Id
        {
            get { return id; }
            set { id = value; }
        }
        public string Maker
        {
            get { return maker; }
            set { maker = value; }
        }
        public string Model
        {
            get { return model; }
            set { model = value; }
        }
        public int Year
        {
            get { return year; }
            set { year = value; }
        }
        public double Price
        {
            get { return price; }
            set { price = value; }
        }


        // Input and Output
        public virtual void Input()
        {
            Console.Write("\tId: ");
            id = Console.ReadLine();
            Console.Write("\tMaker: ");
            maker = Console.ReadLine();
            Console.Write("\tModel: ");
            model = Console.ReadLine();
            Console.Write("\tYear: ");
            year = int.Parse(Console.ReadLine());
            Console.Write("\tPrice: ");
            price = double.Parse(Console.ReadLine());
        }

        public virtual void Output()
        {
            Console.Write("\n{0,-15} {1,-15} {2,-15} {3,-15} {4,-15}", id, maker, model, year, price);
        }

        // ghi de Equals()
        public override bool Equals(object obj)
        {
             Vehicles vehicles = obj as Vehicles;
            if(this.id.Equals(vehicles.id, StringComparison.OrdinalIgnoreCase)) return true;
            return false;
        }

        // ghi de toString()
        public override string ToString()
        {
            return (
                id + "; " + maker + "; " + model + "; " + year + "; " + price
                );
        }
    }
}
