package Bai1;
import Bai1.NhanVien;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NhanVien a = new NhanVien();
        NhanVien b = new NhanVien();
        System.out.println("\n>>>NHẬP THÔNG TIN CỦA NHÂN VIÊN THỨ 1");
        a.input();
        System.out.println("\n>>>NHẬP THÔNG TIN CỦA NHÂN VIÊN THỨ 2");
        b.input();
        System.out.println("\n\nBẢNG THÔNG ITN CỦA HAI NHÂN VIÊN VỪA NHẬP LÀ: ");
        a.xuaTieuDe();
        a.inDL();
        b.inDL();

        /*
        * Nhập vào 1 mảng Nhân viên, in mảng sau khi nhập.
        - In danh sách nhân viên vượt chuẩn
        * */
        int n;
        do{
            System.out.print("\nNhập số lượng nhân viên trong danh sách n > 0: ");
            n = sc.nextInt();
        }while(n < 1);
        NhanVien[] listNV = new NhanVien[n];
        for (int i = 0; i < n; i++) {
            listNV[i] = new NhanVien();
        }
        for (int i = 0; i < n; i++) {
            System.out.println("\n>>>NHẬP THÔNG TIN CỦA NHÂN VIÊN THỨ " + i + 1+ " trong mảng");
            listNV[i].input();
        }
        System.out.println("\n\nBẢNG THÔNG ITN CỦA CÁC NHÂN VIÊN VỪA NHẬP TRONG MẢNG LÀ: ");
        a.xuaTieuDe();
        for(int i = 0; i < n; i++)
        {
            listNV[i].inDL();
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(listNV[i].coVuotChuan()) count++;

        }
       if(count == 0)
           System.out.println("\nKhông có nhân viên nào trong mảng vượt chuẩn cả");
       else {
           System.out.println("\n\nBẢNG THÔNG ITN CỦA CÁC NHÂN VIÊN TRONG MẢNG VƯỢT CHUẨN LÀ: ");
           a.xuaTieuDe();
           for (int i = 0; i < n; i++) {
               if(listNV[i].coVuotChuan())
                   listNV[i].inDL();
           }
       }
    }
}
