package bai8;

import java.util.Scanner;

public class NhanVien {

    static Scanner sc = new Scanner(System.in);
    private String maNV;
    private String tenNV;

    public NhanVien() {
    }

    public NhanVien(String maNV, String tenNV) {
        this.maNV = maNV;
        this.tenNV = tenNV;
    }
    
    public String getMaNV() {
        return maNV;
    }

    public void setMaNV(String maNV) {
        this.maNV = maNV;
    }

    public String getTenNV() {
        return tenNV;
    }

    public void setTenNV(String tenNV) {
        this.tenNV = tenNV;
    }
    public void input() {
        System.out.print("\tMa nhan vien: ");
        maNV = sc.nextLine();
        do {
            System.out.print("\tTen nhan vien: ");
            tenNV = sc.nextLine();
        } while ("".equals(tenNV.trim()));
    }
    
    public String nhanQua()
    {
        return "Nhan qua " + Math.floor( (Math.random()*100));
    }
    
    public void output()
    {
        System.out.printf("\n%8s%35s%35s", maNV, tenNV, nhanQua() );
    }

    String getTen() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
