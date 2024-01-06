using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phieu1_Bai2
{
    internal class Circle
    {
		private float _radius;

        // getter and setter
		public float Radius
		{
			get { return _radius; }
			set { _radius = value; }
		}

        // constructor
        public Circle()
        {
            
        }
        public Circle(float radius)
        {
            this._radius = radius;
        }

        public double Area()
        {
            return _radius * _radius * Math.PI;
        }

        public double Perimeter()
        {
            return 2* _radius * Math.PI;
        }
    }
}
