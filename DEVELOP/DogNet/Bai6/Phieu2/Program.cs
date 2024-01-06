using System.Collections;
using System.Diagnostics.Metrics;
using System.Diagnostics;
using System.Reflection;
using System.Security.Cryptography;

namespace Phieu2
{
    internal class Program
    {
        static void InputList(ArrayList list)
        {
            Console.WriteLine("\n==== NHAP 3 DOI TUONG CAR VA 3 DOI TUONG TRUCK");
            for(int i = 0; i < 3; i++)
            {
                bool isCheckID = false;
                Console.WriteLine(">>> CAR THU " + (i + 1));
                Car car = new Car();
                car.Input();
                if (list.Count > 0)
                {
                    for (int j = 0; j < list.Count; j++)
                    {
                        if (list[j].GetType() == typeof(Car))
                        {
                            if (((Car)list[j]).Id.Equals(car.Id, StringComparison.OrdinalIgnoreCase))
                            {
                                isCheckID = true;
                                Console.WriteLine("ID da ton tai");
                                --i;
                            }
                        }
                        else if (((Truck)list[j]).Id.Equals(car.Id, StringComparison.OrdinalIgnoreCase))
                        {
                            isCheckID = true;
                            Console.WriteLine("ID da ton tai");
                            --i;
                        }
                    }
                    if (!isCheckID) list.Add(car);
                    
                       
                }
                else list.Add(car);
            }
            for(int i = 0; i < 3;i++)
            {
                bool isCheckID = false;
                Console.WriteLine(">>> TRUCK THU " + (i + 1));
                Truck truck = new Truck();
                truck.Input();
                if (list.Count > 0)
                {
                    for (int j = 0; j < list.Count; j++)
                    {
                        if (list[j].GetType() == typeof(Car))
                        {
                            if (((Car)list[j]).Id.Equals(truck.Id, StringComparison.OrdinalIgnoreCase))
                            {
                                isCheckID = true;
                                Console.WriteLine("ID da ton tai");
                                --i;
                            }
                        } else if (((Truck)list[j]).Id.Equals(truck.Id, StringComparison.OrdinalIgnoreCase))
                        {
                            isCheckID = true;
                            Console.WriteLine("ID da ton tai");
                            --i;
                        }
                    }
                    if (!isCheckID) list.Add(truck);
                }
                else list.Add(truck);
            }
        }

        static void OutputList(ArrayList list)
        {
            if(list.Count > 0)
            {
                Console.Write("\n{0,8} {1,15} {2,15} {3,15} {4,15} {5,15} {6,15}", "ID", "MAKER", "MODEL", "YEAR", "PRICE", "CORLOR", "TRUCKLOAD");
                foreach (var item in list)
                {
                    if (item.GetType() == typeof(Car))
                    {
                        (item as Car).Output();
                    }
                    else
                        (item as Truck).Output();
                }
            }else
            { Console.WriteLine("\nDanh sach rong!!!"); }
        }

        static void searchByID(ArrayList list)
        {
            if(list.Count > 0)
            {
                int count = 0;
                string id;
                do
                {
                    Console.Write("\nNhap ID can tim kiem: ");
                    id = Console.ReadLine();
                } while (id == null || id.Trim() == "");
                foreach (var item in list)
                {
                    if (item.GetType() == typeof(Car))
                    {
                        if (((Car)item).Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                        {
                            count++;
                        }
                    }
                    else if (((Truck)item).Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                    }
                }
                if (count == 0) Console.WriteLine("\nTrong danh sach khong co ID: " + id);
                else
                {
                    Console.WriteLine("\n\n==== THONG TIN ITEM CO ID: {0,1} LA: ", id);
                    Console.Write("\n{0,8} {1,15} {2,15} {3,15} {4,15} {5,15} {6,15}", "ID", "MAKER", "MODEL", "YEAR", "PRICE", "CORLOR", "TRUCKLOAD");
                    foreach (var item in list)
                    {
                        if (item.GetType() == typeof(Car))
                        {
                            if (((Car)item).Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                            {
                                (item as Car).Output();
                            }
                        }
                        else if (((Truck)item).Id.Equals(id, StringComparison.OrdinalIgnoreCase))
                        {
                            (item as Truck).Output();
                        }
                    }
                }
            }else Console.WriteLine("\nDanh sach rong!!!");
        }
        static void searchByMarker(ArrayList list)
        {
            if (list.Count > 0)
            {
                int count = 0;
                string marker;
                do
                {
                    Console.Write("\nNhap MARKET can tim kiem: ");
                    marker = Console.ReadLine();
                } while (marker == null || marker.Trim() == "");
                foreach (var item in list)
                {
                    if (item.GetType() == typeof(Car))
                    {
                        if (((Car)item).Maker.Equals(marker, StringComparison.OrdinalIgnoreCase))
                        {
                            count++;
                        }
                    }
                    else if (((Truck)item).Maker.Equals(marker, StringComparison.OrdinalIgnoreCase))
                    {
                        count++;
                    }
                }
                if (count == 0) Console.WriteLine("\nTrong danh sach khong co ID: " + marker);
                else
                {
                    Console.WriteLine("\n\n==== THONG TIN ITEM CO MARKER: {0,1} LA: ", marker);
                    Console.Write("\n{0,8} {1,15} {2,15} {3,15} {4,15} {5,15} {6,15}", "ID", "MAKER", "MODEL", "YEAR", "PRICE", "CORLOR", "TRUCKLOAD");
                    foreach (var item in list)
                    {
                        if (item.GetType() == typeof(Car))
                        {
                            if (((Car)item).Maker.Equals(marker, StringComparison.OrdinalIgnoreCase))
                            {
                                (item as Car).Output();
                            }
                        }
                        else if (((Truck)item).Maker.Equals(marker, StringComparison.OrdinalIgnoreCase))
                        {
                            (item as Truck).Output();
                        }
                    }
                }
            }
            else Console.WriteLine("\nDanh sach rong!!!");
        }

        // OrderByDescending: sap xep giam dan
        // OrderBy: sap xep tang
        static ArrayList sortByPrice(ArrayList list)
        {
            list.Sort(delegate (Object x, Object y)
            {
                double a, b;
                if (x.GetType() == typeof(Car))
                {
                    a = ((Car)x).Price;
                }
                else a = ((Truck)x).Price;
                if (y.GetType() == typeof(Car))
                {
                    b = ((Car)y).Price;
                }
                else b = ((Truck)y).Price;
                return a.CompareTo(b);
            });
            return list;
        }
        static void Main(string[] args)
        {
            try
            {
                int choose;
                ArrayList list = new ArrayList();
                do
                {
                    Console.WriteLine("\n==== MENU ====");
                    Console.WriteLine("1. Nhap du lieu");
                    Console.WriteLine("2. Hien thi du lieu");
                    Console.WriteLine("3. Tim kiem theo id");
                    Console.WriteLine("4. Tim kiem theo maker");
                    Console.WriteLine("5. Sap xep theo price");
                    Console.WriteLine("6. Sap xep theo year");
                    Console.WriteLine("7. Ket thuc");
                    do
                    {
                        Console.Write("Nhap lua chon cua ban: ");
                        choose = int.Parse(Console.ReadLine());

                    } while (choose <= 0 || choose > 7);
                    switch (choose)
                    {
                        case 1:
                            {
                                InputList(list);
                            }; break;
                        case 2:
                            {
                                if (list.Count > 0)
                                {
                                    Console.WriteLine("\n==== BANG THONG TIN TRUCK VA CAR VUA NHAP ====");
                                    OutputList(list);
                                }
                                else
                                    OutputList(list);
                            }; break;
                        case 3:
                            {
                                searchByID(list);
                            }; break;
                        case 4: { 
                                searchByMarker(list);
                        }; break;
                        case 5: { }; break;
                        case 6: { }; break;
                        case 7: { return; };
                    }
                } while (true);
            }
            catch (FormatException e) {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine("\nSai dinh dang du lieu!!!");
                Console.ResetColor();
            }
        }
    }
}