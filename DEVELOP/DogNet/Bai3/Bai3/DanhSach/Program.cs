namespace DanhSach
{
    internal class Program
    {
        public static void output(List<float> arr)
        { 
            foreach (float item in arr)
            {
                Console.Write(item + "\t");
            }
        }
        static void Main(string[] args)
        {
            //Viết chương trinh cho phép tạo ra một List các số thực. Thêm vào danh sách 5 
            //phần tử nhập vào từ bàn phím.Sắp xếp danh sách theo thứ tự tăng dần
            List<float> arrFloats = new List<float>();
            int i = 0;
            while (true)
            {
                Console.Write("Nhap phan tu thu {0} cua mang (nhap 'q' de thoat): ", i + 1);
                string input = Console.ReadLine();
                if (input.ToLower() == "q")
                {
                    break;
                }
                if (float.TryParse(input, out float a))
                {
                    arrFloats.Add(a);
                    i++;
                }
                else
                {
                    Console.WriteLine("Du lieu nhap khong hop le. Vui long nhap lai.");
                }
            }
            Console.WriteLine("\nMang vua nhap la: ");
            output(arrFloats);
            Console.WriteLine("\nMang sau khi sap xep la: ");
            arrFloats.Sort();
            output(arrFloats);

            //Kiểm tra xem trong danh sách có số âm không, nếu có hãy xóa nó ra khỏi 
            //danh sách
            i = 0;
            foreach (float item in arrFloats)
            {
                if(item < 0)
                {
                    i++;
                    break;
                }    
            }

            if (i == 0)
                Console.WriteLine("\nTrong mang khong co phan tu nao am");
            else
            {
                Console.WriteLine("\nMang sau khi xoa cac phan tu am la: ");
                arrFloats.RemoveAll(item => item < 0);
                output(arrFloats);
            }

            //Nhập vào từ bàn phím một số x bất kỳ. Chèn x vào vị trí đúng thứ tự và in ra 
            //danh sách đã bổ sung
            float x;
            Console.Write("\nNhap x: ");
            x = float.Parse(Console.ReadLine());
            arrFloats.Add(x);
            Console.WriteLine("\nMang bo sung la: ");
            arrFloats.Sort();
            output(arrFloats);
        }
    }
}