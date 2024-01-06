using System;
using System.IO;
namespace Bai2 { 
    class Bai7
    {
        static void Main(string[] args)
        {
            
            StreamWriter d = new StreamWriter(@"d:\target\example.txt", true);
            StreamReader c = new StreamReader(@"C:\source\example.txt");
            
            try
            {
                while(c.Peek() != -1)
                {
                    Console.WriteLine(c.ReadLine());
                }    
            }
            catch (Exception ex)
            {
                Console.WriteLine("Lỗi khi sao chép file: " + ex.Message);
            }
            d.Close();
        }
    }
}

