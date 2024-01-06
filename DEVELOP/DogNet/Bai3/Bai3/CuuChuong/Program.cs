namespace CuuChuong
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("BANG CUU CHUONG");   
            for(int i = 1; i <= 9; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    Console.Write("{0} x {1} = {2,-5}", j, i, (i * j));
                }  
                Console.WriteLine("\n");
            }
        }
    }
}