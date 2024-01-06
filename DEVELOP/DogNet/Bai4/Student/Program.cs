namespace Phieu1_Bai3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Student student1 = new Student("1", "Trang", 9);
            Console.WriteLine("===== THONG TIN STUDENT {0} =====", student1.Name );
            Console.WriteLine(student1);

            Student student2 = new Student("2", "Lan", 6);
            Console.WriteLine("===== THONG TIN STUDENT {0} =====", student2.Name);
            Console.WriteLine(student2);

            Student student3 = new Student("3", "Minh", 8);
            Console.WriteLine("===== THONG TIN STUDENT {0} =====", student3.Name);
            Console.WriteLine(student3);

        }
    }
}