using static System.Net.Mime.MediaTypeNames;

namespace TapTin
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader readFile = new StreamReader(@"D:\HAUI\LAP_TRINH\DogNet\demo.txt");
            StreamWriter writeFile = new StreamWriter(@"D:\HAUI\LAP_TRINH\DogNet\demo_write.txt", true);
            string text = File.ReadAllText(@"D:\HAUI\LAP_TRINH\DogNet\demo.txt");
            string[] words = text.Split(new char[] { ' ', '\n', '\r', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            int wordCount = words.Length;
            while (readFile.Peek() != -1)
            {
                writeFile.WriteLine(readFile.ReadLine().ToUpper());
               
            }
            readFile.Close();
            writeFile.WriteLine(wordCount);
            writeFile.Close();
            Console.WriteLine("Xu ly hoan tat");
        }
    }
}