package bai8;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    // Nhập danh sách nhân viên
    static QuanLyNhanVien inputNV() {
        QuanLyNhanVien a = new QuanLyNhanVien();
        int n;
        do {
            System.out.print("\nNhap so luong nhan vien can them: ");
            n = sc.nextInt();
        } while (n < 1);
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            NhanVien nv = new NhanVien();
            System.out.print("\nNhap nhan vien thu " + (i + 1) + ": \n");
            nv.input();
            a.themNhanVien(nv);
        }
        return a;
    }
    
    static void outputNV(QuanLyNhanVien a )
    {
        
         ArrayList<NhanVien> danhSachNhanVien = a.layDanhSachNhanVien();
        a.printTitle();
        for (NhanVien nhanVien : danhSachNhanVien) {
            nhanVien.output();
        }
    }

    public static void main(String[] args) {
        QuanLySanPham quanLySanPham = new QuanLySanPham();

        // Thêm nhân viên
        QuanLyNhanVien quanLyNhanVien = inputNV();
        // Lấy danh sách nhân viên
          ArrayList<NhanVien> danhSachNhanVien = quanLyNhanVien.layDanhSachNhanVien();
        outputNV(quanLyNhanVien);

        // Lấy tên sản phẩm mới
        String tenSanPhamMoi = quanLySanPham.layTenSanPhamMoi(danhSachNhanVien);
        System.out.println("\nTen san pham moi: " + tenSanPhamMoi);

        // Lấy tên sản phẩm phổ biến nhất
        String tenSanPhamPhoBien = quanLySanPham.layTenPhoBienNhat();
        System.out.println("\nTen sp pho bien: " + tenSanPhamPhoBien);
    }
}
