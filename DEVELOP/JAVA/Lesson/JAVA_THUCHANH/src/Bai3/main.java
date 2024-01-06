package Bai3;
import Bai3.KhachHangVN;
import Bai3.KhachHangNN;
import java.util.Scanner;

public class main {
    static Scanner sc = new Scanner(System.in);

    // Nhập xuất danh sách các hóa đơn khách hàng.
    static KhachHangVN[] nhapDSKHVN()
    {
        int n;
        do{
            System.out.print("Nhập số lượng khách hàng Việt Nam n >= 0: ");
            n = sc.nextInt();
        }while(n < 0);
        if(n == 0) return null;
        KhachHangVN[] listKH = new KhachHangVN[n];
        for(int i = 0; i < n; i++)
            listKH[i] = new KhachHangVN();
        for (int i = 0; i < n; i++)
        {
            System.out.println("==== NHẬP THÔNG TIN KHÁCH HÀNG VIỆT NAM THỨ " + (i+1) + " ====");
            listKH[i].input();
        }
        return listKH;
    }

    static KhachHangNN[] nhapDSKHNN()
    {
        int m;
        do{
            System.out.print("Nhập số lượng khách hàng Nước Ngoài m >= 0: ");
            m = sc.nextInt();
        }while(m < 0);
        if(m == 0) return null;
        KhachHangNN[] listKH = new KhachHangNN[m];
        for(int i = 0; i < m; i++)
            listKH[i] = new KhachHangNN();
        for (int i = 0; i < m; i++)
        {
            System.out.println("==== NHẬP THÔNG TIN KHÁCH HÀNG NƯỚC NGOÀI THỨ " + (i+1) + " ====");
            listKH[i].input();
        }
        return listKH;
    }
    static void xuatDSKHVN(KhachHangVN[] arr)
    {
       if(arr != null)
       {
           System.out.println("\n\nBẢNG HÓA ĐƠN TIỀN ĐIỆN CỦA KHÁCH HÀNG VIỆT NAM:");
           System.out.printf("%8s%15s%15s%15s%15s%15s%15s%15s","Mã KH", "Họ tên KH", "Ngày ra đơn", "Số lượng", "Đơn giá","Đối tượng", "Định mức", "Thành tiền");
           for(int i = 0; i < arr.length; i++)
           {
               arr[i].output();
           }
       }
    }

    static void xuatDSKHNN(KhachHangNN[] arr)
    {
        if(arr != null)
        {
            System.out.println("\n\nBẢNG HÓA ĐƠN TIỀN ĐIỆN CỦA KHÁCH HÀNG NƯỚC NGOÀI:");
            System.out.printf("%8s%15s%15s%15s%15s%15s%15s","Mã KH", "Họ tên KH", "Ngày ra đơn", "Số lượng", "Đơn giá","Quốc tịch", "Thành tiền");
            for(int i = 0; i < arr.length; i++)
            {
                arr[i].output();
            }
        }
    }
    // Tính tổng số lượng cho từng loại khách hàng.
    static long tongSLKHVN(KhachHangVN[] arr)
    {
       if(arr != null)
       {
           long sum = 0;
           for(int i = 0; i < arr.length; i++)
           {
               sum += arr[i].getSoLuong();
           }
           return sum;
       }
       return -1;
    }

    static long tongSLKHNN(KhachHangNN[] arr)
    {
        if(arr != null)
        {
            long sum = 0;
            for(int i = 0; i < arr.length; i++)
            {
                sum += arr[i].getSoLuong();
            }
            return sum;
        }
        return -1;
    }
    //Tính trung bình thành tiền của khách hàng người nước ngoài
    static double tbThanhTienCuaKHNN(KhachHangNN[] arr)
    {
        if(arr == null)
        {
            return -1;
        }
        double tb = 0;
        for (int i = 0; i < arr.length; i++ )
            tb += arr[i].thanhTien();
        return tb/(arr.length);
    }
    //Xuất ra các hoá đơn trong tháng 09 năm 2013 (cùa cả 2 loại khách hàng)
    static void inHDNgay9_2013(KhachHangNN[] arr, KhachHangVN[] arr1)
    {
        if(arr == null && arr1 == null)
            System.out.println("Không có khách hàng trong nước hay ngoài nước trong danh sách hóa đơn");
        else{
            int count = 0, count1 = 0;
            for (int i = 0; i < arr.length; i++) {
                if(arr[i].getNgayRaDon().getThang() == 9 && arr[i].getNgayRaDon().getNam() == 2013)
                {
                    count++;
                    if(count > 0) break;
                }
            }
            for (int i = 0; i < arr.length; i++) {
                if(arr1[i].getNgayRaDon().getThang() == 9 && arr1[i].getNgayRaDon().getNam() == 2013)
                {
                    count1++;
                    if(count1 > 0) break;
                }
            }
            if(count1 == 0)
                System.out.println("\nKhông có hóa đơn tiền điện của khách hàng Việt Nam nào trong tháng 09 năm 2013");
            else{
                System.out.println("\n\nBẢNG HÓA ĐƠN TIỀN ĐIỆN CỦA KHÁCH HÀNG VIỆT NAM TRONG THÁNG 9 NĂM 2013:");
                System.out.printf("%8s%15s%15s%15s%15s%15s%15s%15s","Mã KH", "Họ tên KH", "Ngày ra đơn", "Số lượng", "Đơn giá","Đối tượng", "Định mức", "Thành tiền");
                for (int i = 0; i < arr.length; i++)
                    if(arr1[i].getNgayRaDon().getThang() == 9 && arr1[i].getNgayRaDon().getNam() == 2013)
                        arr1[i].output();
            }
            if(count == 0)
                System.out.println("\nKhông có hóa đơn tiền điện của khách hàng nước ngoài nào trong tháng 09 năm 2013");
            else{
                System.out.println("\n\nBẢNG HÓA ĐƠN TIỀN ĐIỆN CỦA KHÁCH HÀNG NƯỚC NGOÀI TRONG THÁNG 9 NĂM 2013:");
                System.out.printf("%8s%15s%15s%15s%15s%15s%15s","Mã KH", "Họ tên KH", "Ngày ra đơn", "Số lượng", "Đơn giá","Quốc tịch", "Thành tiền");
                for (int i = 0; i < arr.length; i++)
                    if(arr[i].getNgayRaDon().getThang() == 9 && arr[i].getNgayRaDon().getNam() == 2013)
                        arr[i].output();
            }

        }
    }
    public static void main(String[] args) {
        KhachHangVN[] listKHVN = nhapDSKHVN();
        KhachHangNN[] listKHNN = nhapDSKHNN();
        xuatDSKHVN(listKHVN);
        if(tongSLKHVN(listKHVN) != -1)
            System.out.printf("\n%15s%25s","Tổng số lượng điện tiêu thụ:", tongSLKHVN(listKHVN));
        xuatDSKHNN(listKHNN);
        if(tongSLKHNN(listKHNN) != -1)
            System.out.printf("\n%15s%25s","Tổng số lượng điện tiêu thụ:", tongSLKHNN(listKHNN));
        if(tbThanhTienCuaKHNN(listKHNN) != -1)
            System.out.printf("\n%15s%44s","Trung bình thành tiền của khách hàng người nước ngoài:", tbThanhTienCuaKHNN(listKHNN));
        inHDNgay9_2013(listKHNN, listKHVN);
        in();
    }
    static void in()
    {
        System.out.println("adkksafj");
    }
}
