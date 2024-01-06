package Bai2;

import java.util.Scanner;

public class SinhVien {
    Scanner sc = new Scanner(System.in);
    private int maSV;
    private String hoTen;
    private float diemLT;
    private float diemTH;

    public SinhVien(){}

    public SinhVien(int maSV, String hoTen, float diemLT, float diemTH) {
        this.maSV = maSV;
        this.hoTen = hoTen;
        this.diemLT = diemLT;
        this.diemTH = diemTH;
    }

    public int getMaSV() {
        return maSV;
    }

    public void setMaSV(int maSV) {
        this.maSV = maSV;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public float getDiemLT() {
        return diemLT;
    }

    public void setDiemLT(float diemLT) {
        this.diemLT = diemLT;
    }

    public float getDiemTH() {
        return diemTH;
    }

    public void setDiemTH(float diemTH) {
        this.diemTH = diemTH;
    }
    public void nhap()
    {
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
    }

    public float diemTB()
    {
        return (diemTH + diemLT)/2;
    }
    public String toString()
    {
        return (
                "Mã SV: " + maSV + "\nHọ tên sinh viên: "
                        + hoTen + "\nĐiểm lý thuyết: " + diemLT
                        + "\nĐiểm thực hành: " + diemTH
                        +"\nĐiểm trung bình: " + diemTB()
                );
    }
    public void inTieuDe()
    {
        System.out.printf("%8s%15s%15s%15s%15s", "Mã SV", "Họ tên SV", "Điểm LT", "Điểm TH", "Điểm TB");
    }
    public void inDuLieu()
    {
        System.out.printf("\n%8s%15s%15s%15s%15s", maSV, hoTen, diemLT, diemTH, diemTB());
    }

}
