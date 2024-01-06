using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu2
{
    internal class Vehicles : IVehicle, Icomparable
    {
        protected string id;
        protected string maker;
        protected string model;
        protected int year;
        protected double price;

        // getter and setter
        public string Id
        { 
            get { return id; }
            set { id = value; }
        }
        public string Maker
        { 
            get { return maker; } 
            set {  maker = value; } 
        }

        public string Model
        { 
            get { return model; } 
            set {  model = value; } 
        }

        public int Year
        { 
            get { return year; } 
            set {  year = value; } 
        }

        public double Price
        { 
            get { return price; } 
            set {  price = value; } 
        }

        // constructor
        public Vehicles()
        {
            
        }

        public Vehicles(string id, string maker, string model, int year, double price)
        {
            this.id = id;
            this.maker = maker;
            this.model = model;
            this.year = year;
            this.price = price;
        }

        // method
        public virtual void Input()
        {
            Console.Write("\tID: ");
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
            Console.Write("\n{0,8} {1,15} {2,15} {3,15} {4,15}", id,maker, model, year, price);
        }

        // ghi de
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType())
            {
                return false;
            }

            Vehicles otherVehicle = (Vehicles)obj;
            return id == otherVehicle.id;
        }

        public override string ToString()
        {
            return (
                "\nId: " + id
                + "\nMaker: " + maker
                + "\nModel: " + model
                + "\nYear: " + year
                + "\nPrice: " + price
           );

        }

        public int ComparaTo(object obj)
        {
            Vehicles vehicles = (Vehicles)obj;
            return (this.price.CompareTo(vehicles.price));
        }
    }
}
