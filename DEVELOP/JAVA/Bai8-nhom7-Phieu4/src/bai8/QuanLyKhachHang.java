package bai8;
import java.util.ArrayList;
import java.util.TreeSet;

class QuanLyKhachHang {
    private TreeSet<KhachHang> danhSachKhachHang ;

    public QuanLyKhachHang() {
        danhSachKhachHang = new TreeSet<>();
    }

    public void themKhachHang(KhachHang khachHang) {
        danhSachKhachHang.add(khachHang);
    }

    public void suaKhachHang(KhachHang khachHang) {
        for (KhachHang kh : danhSachKhachHang) {
            if (kh.getMaKhachHang().equals(khachHang.getMaKhachHang())) {
                kh.setTenKhachHang(khachHang.getTenKhachHang());
                break;
            }
        }
    }
    
     public void xoaKhachHang(KhachHang khachHang) {
        danhSachKhachHang.remove(khachHang);
    }
}