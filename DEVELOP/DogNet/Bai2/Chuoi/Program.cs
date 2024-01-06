using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
namespace Chuoi
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            Console.Write("Nhap chuoi: ");
            str = Console.ReadLine();

            //Cho phép người dùng nhập vào một chuỗi, hiển thị mỗi ký tự trong chuỗi
            //trên 1 dòng.
            Console.WriteLine("Hien thi chuoi ky tu trong chuoi tren 1 dong: ");
            foreach(char a in str.ToCharArray()) {
                Console.WriteLine(a);
            }


            //Cho phép người dùng nhập vào một chuỗi gồm các ký tự và khoảng trắng, hiển thị
            //mỗi từ trên 1 dòng(bỏ qua các khoảng trắng thừa).

            Console.WriteLine("Hien thi moi tu tren 1 dong bo qua cac ky tu khoang trang");
            foreach(string a in str.Split(" ", StringSplitOptions.RemoveEmptyEntries))
            {
                Console.WriteLine(a.Trim());
            }


            // Cho phép người dùng nhập vào một chuỗi, hiển thị số lần xuất hiện của mỗi
            //ký tự trong chuỗi.
            Dictionary<char, int> charCounts = str
            .GroupBy(c => c)
            .ToDictionary(g => g.Key, g => g.Count());
            foreach (var kvp in charCounts)
            {
                Console.WriteLine($"Ky tu '{kvp.Key}' xuat hien {kvp.Value} lan");
            }
        }
    }
}
