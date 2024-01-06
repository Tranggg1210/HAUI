package bai8;

import java.util.ArrayList;
import java.util.Scanner;

public class QuanLyNhanVien {
    private final ArrayList<NhanVien> danhSachNhanVien;

    public QuanLyNhanVien() {
        danhSachNhanVien = new ArrayList<>();
    }

    public void themNhanVien(NhanVien nhanVien) {
        danhSachNhanVien.add(nhanVien);
    }

    public void xoaNhanVien(NhanVien nhanVien) {
        danhSachNhanVien.remove(nhanVien);
    }

    public ArrayList<NhanVien> layDanhSachNhanVien() {
        return danhSachNhanVien;
    }
     public void  printTitle()
    {
           System.out.printf("\n%8s%35s%35s", "Ma NV", "Ten NV", "QUA");
    }

}