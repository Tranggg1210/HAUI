package Bai3;

import Bai3.Date;

import java.util.Scanner;

public abstract class KhachHang {

    Scanner sc = new Scanner(System.in);
    private long maKH;
    private String hoTen;
    private Date ngayRaDon = new Date();
    private int soLuong;
    private long donGia;

    public KhachHang(){}
    public KhachHang(long maKH, String hoTen, Date ngayRaDon, int soLuong, long donGia) {
        this.maKH = maKH;
        this.hoTen = hoTen;
        this.ngayRaDon = ngayRaDon;
        this.soLuong = soLuong;
        this.donGia = donGia;
    }

    public long getMaKH() {
        return maKH;
    }

    public void setMaKH(long maKH) {
        this.maKH = maKH;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public Date getNgayRaDon() {
        return ngayRaDon;
    }

    public void setNgayRaDon(Date ngayRaDon) {
        this.ngayRaDon = ngayRaDon;
    }

    public int getSoLuong() {
        return soLuong;
    }

    public void setSoLuong(int soLuong) {
        this.soLuong = soLuong;
    }

    public long getDonGia() {
        return donGia;
    }

    public void setDonGia(long donGia) {
        this.donGia = donGia;
    }

    public abstract double thanhTien();
    public void input()
    {
        System.out.print("\tMã khách hàng: ");
        maKH = sc.nextLong();
        sc.nextLine();
        System.out.print("\tHọ tên KH: ");
        hoTen = sc.nextLine();
        ngayRaDon.input();
        System.out.print("\tSố lượng điện tiêu thụ: ");
        soLuong = sc.nextInt();
        System.out.print("\tĐơn giá: ");
        donGia = sc.nextLong();
    }

    public void output()
    {
        System.out.printf("\n%8s%15s", maKH, hoTen);
        ngayRaDon.output();
        System.out.printf("%15s%15s", soLuong, donGia);
    }
}
