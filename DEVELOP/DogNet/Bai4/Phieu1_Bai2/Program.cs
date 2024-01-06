namespace Phieu1_Bai2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Circle circle = new Circle(5.6f);
            Console.WriteLine("Circle' area has radius = {0} la {1}",circle.Radius, circle.Area().ToString("0.00"));
            Console.WriteLine("Circle' perimeter has radius = {0} la {1}", circle.Radius, circle.Perimeter().ToString("0.00"));
        }
    }
}