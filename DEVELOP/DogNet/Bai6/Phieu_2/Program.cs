using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Phieu_2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Vehicles> list = new List<Vehicles>();
            try
            {
                int choose;
                do
                {
                    Console.WriteLine("\n===============================");
                    Console.WriteLine("1.Nhap du lieu");
                    Console.WriteLine("2.Hien thi du lieu");
                    Console.WriteLine("3.Tim kiem theo id");
                    Console.WriteLine("4. Tim kiem theo maker");
                    Console.WriteLine("5. Sap xep theo price");
                    Console.WriteLine("6. Sap xep theo year");
                    Console.WriteLine("7. Xoa thong tin theo id");
                    Console.WriteLine("8. Sua thong tin theo id");
                    Console.WriteLine("9. Ket thuc");
                    do
                    {
                        Console.Write("Nhap lua chon cua ban: ");
                        choose = int.Parse(Console.ReadLine());
                    } while (choose <= 0 || choose > 9);

                    switch (choose)
                    {
                        case 1: {
                                Input(list);
                        }; break;
                        case 2: {
                                Console.WriteLine("\n===== DANH SACH CAC DOI TUONG LA ======");
                                Output(list);
                        }; break;
                        case 3: {
                                searchByID(list);    
                        }; break;
                        case 4: { 
                                searchByMaker(list);
                        }; break;
                        case 5: {
                                sortByPrice(list);
                        }; break;
                        case 6: { 
                                sortByPrice(list);
                        }; break;
                        case 7:
                        {
                                deleteByID(list);
                        }; break;
                        case 8:
                        {
                                updateByID(list);
                        }; break;
                        case 9: return;
                    }
                } while (true);
            }catch (FormatException e) {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("Sai dinh dang du lieu!!!");
                Console.ResetColor();
            }
        }
        private static void Input(List<Vehicles> list)
        {
            int n, m;
            do
            {
                Console.Write("\nNhap so luong cua Car: ");
                n = int.Parse(Console.ReadLine());
            } while (n < 0);
            for(int i = 0; i < n; i++)
            {
                Console.WriteLine("===== NHAP THONG TIN CAR THU " + (i+1) + " =====");
                Car car = new Car();
                car.Input();
                bool isCheckID = false;
                do
                {
                    if (list.Count > 0)
                    {
                        foreach (var item in list)
                        {
                            if (item.Id.Equals(car.Id,StringComparison.OrdinalIgnoreCase ))
                            {
                                Console.WriteLine("\n===== ID bi trung, nhap lai thong tin car thu " + (i + 1));

                                car.Input();
                            }
                        }
                        isCheckID = true;
                    } else isCheckID = true;
                } while (!isCheckID);
                list.Add(car);
                
            }
            do
            {
                Console.Write("\nNhap so luong cua Truck: ");
                m = int.Parse(Console.ReadLine());
            } while (m < 0);
            for (int i = 0; i < m; i++)
            {
                Console.WriteLine("===== NHAP THONG TIN TRUCK THU " + (i + 1) + " =====");
                Truck truck = new Truck();
                truck.Input();
                bool isCheckID = false;
                do
                {
                    if (list.Count > 0)
                    {
                        foreach (var item in list)
                        {
                            if (item.Id.Equals(truck.Id, StringComparison.OrdinalIgnoreCase))
                            {
                                Console.WriteLine("\n===== ID bi trung, nhap lai thong tin truck thu " + (i + 1));
                                truck.Input();
                            }
                        }
                        isCheckID = true;
                    }
                    else isCheckID = true;
                } while (!isCheckID);
                list.Add(truck);

            }
        }

        private static void Output(List<Vehicles> list)
        {
            if (list.Count > 0)
            {
                Console.Write("\n{0,-15} {1,-15} {2,-15} {3,-15} {4,-15} {5,-15} {6,-15}", "ID", "Maker", "Model", "Year", "Price", "Color", "Trucload");
                foreach (var item in list)
                {
                    if (item is Car) item.Output();
                    else if (item is Truck) item.Output();
                    else item.Output();
                }
            }else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }

        private static void searchByID(List<Vehicles> list)
        {
            if(list.Count > 0)
            {
                string id;
                int count = 0;
                do
                {
                    Console.WriteLine("\nNhap id ban can tim: ");
                    id = Console.ReadLine();
                } while (string.IsNullOrEmpty(id));
                foreach(var item in list)
                {
                    if(item.Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        break;
                    }
                }
                if(count == 0)
                    Console.WriteLine("\n===> Khong co id ban can tim trong danh sach!!!");
                else
                {
                    Console.WriteLine("\n===== DOI TUONG CO ID BAN CAN TIM LA =====");
                    Console.Write("\n{0,-15} {1,-15} {2,-15} {3,-15} {4,-15} {5,-14} {6,-15}", "ID", "Maker", "Model", "Year", "Price", "Color", "Trucload");
                    foreach (var item in list)
                    {
                        if (item.Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                        {
                            if (item is Car) item.Output();
                            else if (item is Truck) item.Output();
                            else item.Output();

                        }
                    }
                }
            }else Console.WriteLine("\n===> Danh sach rong!!!");

        }

        private static void searchByMaker(List<Vehicles> list)
        {
            if (list.Count > 0)
            {
                string maker;
                int count = 0;
                do
                {
                    Console.WriteLine("\nNhap maker ban can tim: ");
                    maker = Console.ReadLine();
                } while (string.IsNullOrEmpty(maker));
                foreach (var item in list)
                {
                    if (item.Maker.Equals(maker, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        break;
                    }
                }
                if (count == 0)
                    Console.WriteLine("\n===> Khong co maker ban can tim trong danh sach!!!");
                else
                {
                    Console.WriteLine("\n===== CAC DOI TUONG CO MAKER BAN CAN TIM LA =====");
                    Console.Write("\n{0,-15} {1,-15} {2,-15} {3,-15} {4,-15} {5,-14} {6,-15}", "ID", "Maker", "Model", "Year", "Price", "Color", "Trucload");
                    foreach (var item in list)
                    {
                        if (item.Maker.Equals(maker, StringComparison.OrdinalIgnoreCase))
                        {
                            if (item is Car) item.Output();
                            else if (item is Truck) item.Output();
                            else item.Output();

                        }
                    }
                }
            }
            else Console.WriteLine("\n===> Danh sach rong!!!");

        }

        private static void sortByPrice(List<Vehicles> list)
        {
            if (list.Count > 0)
            {
                list.Sort(
                    (v1, v2) => v1.Price.CompareTo(v2.Price)
                 );
                Console.WriteLine("\n===== DANH SACH SAU KHI SAP XEP THEO PRICE =====");
                Output(list);
            }else { Console.WriteLine("\n===> Danh sach rong!!!"); }
            
        }

        private static void sortByYear(List<Vehicles> list)
        {
           if(list.Count > 0)
            {
                list.Sort(
                    (v1, v2) => v1.Year.CompareTo(v2.Year)
                );
                Console.WriteLine("\n===== DANH SACH SAU KHI SAP XEP THEO YEAR =====");
                Output(list);
            }
            else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }

        // xoa
        private static void deleteByID(List<Vehicles> list)
        {
            if (list.Count > 0)
            {
                string id;
                int count = 0;
                do
                {
                    Console.WriteLine("\nNhap id ban can xoa: ");
                    id = Console.ReadLine();
                } while (string.IsNullOrEmpty(id));
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    if (list[i].Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        list.RemoveAt(i);
                        break;
                    }
                }
                if (count == 0)
                    Console.WriteLine("\n===> Khong co id ban can xoa trong danh sach!!!");
                else
                {
                    Console.WriteLine("\n===== DANH SACH SAU KHI XOA =====");
                    Output(list);
                }
            }
            else Console.WriteLine("\n===> Danh sach rong!!!");

        }

        // sua
        private static void updateByID(List<Vehicles> list)
        {
            if (list.Count > 0)
            {
                string id;
                int count = 0;
                do
                {
                    Console.WriteLine("\nNhap id ban can sua: ");
                    id = Console.ReadLine();
                } while (string.IsNullOrEmpty(id));
                for (int i = list.Count - 1; i >= 0; i--)
                {
                    if (list[i].Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                        if (list[i] is Car)
                        {
                            string maker, model, color;
                            int year;
                            double price;
                            Console.WriteLine("\n===== NHAP THONG TIN CAR BAN CAN SUA =====");
                            Console.Write("\tMaker: ");
                            maker = Console.ReadLine();
                            Console.Write("\tModel: ");
                            model = Console.ReadLine();
                            Console.Write("\tYear: ");
                            year = int.Parse(Console.ReadLine());
                            Console.Write("\tPrice: ");
                            price = double.Parse(Console.ReadLine());
                            Console.Write("\tColor: ");
                            color = Console.ReadLine();
                            list[i] = new Car(list[i].Id, maker, model, year, price, color);


                        }else if (list[i] is Truck)
                        {
                            string maker, model;
                            int year, trucload;
                            double price;
                            Console.WriteLine("\n===== NHAP THONG TIN CAR BAN CAN SUA =====");
                            Console.Write("\tMaker: ");
                            maker = Console.ReadLine();
                            Console.Write("\tModel: ");
                            model = Console.ReadLine();
                            Console.Write("\tYear: ");
                            year = int.Parse(Console.ReadLine());
                            Console.Write("\tPrice: ");
                            price = double.Parse(Console.ReadLine());
                            Console.Write("\tColor: ");
                            trucload = int.Parse(Console.ReadLine());
                            list[i] = new Truck(list[i].Id, maker, model, year, price, trucload);
                        }
                    }
                }
                if (count == 0)
                    Console.WriteLine("\n===> Khong co id ban xua xoa trong danh sach!!!");
                else
                {
                    Console.WriteLine("\n===== DANH SACH SAU KHI XOA =====");
                    Output(list);
                }
            }
            else { Console.WriteLine("\n===> Danh sach rong!!!"); }
        }
    }
}