package Bai2;
import Bai2.SinhVien;

import java.sql.SQLOutput;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int maSV;
        String hoTen;
        float diemLT, diemTH;

        // Sv1 chứa thông tin của mình bằng hàm tạo đủ thông số, thông tin truyền
        //vào cho hàm tạo nhập vào từ bàn phím
        System.out.println("\n>>>NHẬP THÔNG TIN SINH VIÊN THỨ 1");
        do{
            System.out.print("\tMã sinh viên: ");
            maSV = sc.nextInt();
        }while(maSV < 0);
        do{
            System.out.print("\tHọ tên: ");
            hoTen = sc.nextLine();
        }while(hoTen.trim() == "");
        do{
            System.out.print("\tĐiểm lý thuyết: ");
            diemLT = sc.nextFloat();
        }while(diemLT < 0 || diemLT > 10);
        do{
            System.out.print("\tĐiểm thực hành: ");
            diemTH = sc.nextFloat();
        }while(diemTH < 0 || diemTH > 10);
        SinhVien sv1 = new SinhVien(maSV, hoTen, diemLT, diemTH);

        //Sv2 thông tin được tạo bằng hàm đủ thông số với các giá trị cố định do
        //người dùng minh họa.
        System.out.println("\n>>>ĐÃ TẠO DỮ LIỆU CHO SINH VIÊN THỨ 2");
        SinhVien sv2 = new SinhVien(2, "Nguyễn Văn A", 9.8f, 8);

        // Sv3 tạo bằng hàm tạo mặc định. Nhập các thông tin vào từ bàn phím và
        //gọi hàm set để gán giá trị cho các thuộc tính
        SinhVien sv3 = new SinhVien();
        System.out.println("\n>>>NHẬP THÔNG TIN SINH VIÊN THỨ 3");
        do{
            System.out.print("\tMã sinh viên: ");
            maSV = sc.nextInt();
        }while(maSV < 0);
        do{
            sc.nextLine();
            System.out.print("\tHọ tên: ");
            hoTen = sc.nextLine();
        }while(hoTen.trim() == "");
        do{
            System.out.print("\tĐiểm lý thuyết: ");
            diemLT = sc.nextFloat();
        }while(diemLT < 0 || diemLT > 10);
        do{
            System.out.print("\tĐiểm thực hành: ");
            diemTH = sc.nextFloat();
        }while(diemTH < 0 || diemTH > 10);
        sv3.setMaSV(maSV);
        sv3.setHoTen(hoTen);
        sv3.setDiemLT(diemLT);
        sv3.setDiemTH(diemTH);


        //Tạo và in bản danh sách sinh viên gồm 4 cột: mã sinh viên, họ tên, điểm
        //lý thuyết, thực hành, điểm trung bình. Bảng có 3 dòng cho 3 sinh viên
        System.out.println("\n>>>BẢNG DANH SÁCH SINH VIÊN");
        sv1.inTieuDe();
        sv1.inDuLieu();
        sv2.inDuLieu();
        sv3.inDuLieu();

        //Đưa ra sinh viên có điểm trung bình lớn nhất trong danh sách.
        int count = 0;
        float diemtb = sv1.diemTB();
        if(diemtb < sv2.diemTB()) diemtb = sv2.diemTB();
        if(diemtb < sv3.diemTB()) diemtb = sv3.diemTB();
        if(diemtb == sv1.diemTB()) count++;
        if(diemtb == sv2.diemTB()) count++;
        if(diemtb == sv3.diemTB()) count++;
        if(count >= 2)
        {
            System.out.println("\n>>>BẢNG DANH SÁCH CÁC SINH VIÊN CÓ ĐIỂM TRUNG BÌNH CAO NHẤT");
            sv1.inTieuDe();
            if(diemtb == sv1.diemTB()) sv1.inDuLieu();
            if(diemtb == sv2.diemTB()) sv1.inDuLieu();
            if(diemtb == sv3.diemTB()) sv2.inDuLieu();
        }else{
            System.out.println("\n>>>SINH VIÊN CÓ ĐIỂM TRUNG BÌNH CAO NHẤT");
            sv1.inTieuDe();
            if(diemtb == sv1.diemTB()) sv1.inDuLieu();
            if(diemtb == sv2.diemTB()) sv1.inDuLieu();
            if(diemtb == sv3.diemTB()) sv2.inDuLieu();
        }
    }
}
