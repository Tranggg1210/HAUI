package bai8;

import java.util.Scanner;

class KhachHang {
    static Scanner sc = new Scanner(System.in);
    private String maKhachHang;
    private String tenKhachHang;

    public KhachHang(String maKhachHang, String tenKhachHang) {
        this.maKhachHang = maKhachHang;
        this.tenKhachHang = tenKhachHang;
    }

    public String getMaKhachHang() {
        return maKhachHang;
    }

    public String getTenKhachHang() {
        return tenKhachHang;
    }

    public void setTenKhachHang(String tenKhachHang) {
        this.tenKhachHang = tenKhachHang;
    }
    
      public void input() {
        System.out.println("\tMa khach hang: ");
        maKhachHang = sc.nextLine();
        do {
            System.out.println("\tTen khach hang: ");
            tenKhachHang = sc.nextLine();
        } while ("".equals(tenKhachHang.trim()));
    }
   
    public void  printTitle()
    {
           System.out.printf("\n%8s%15s", "Ma KH", "Ten KH");
    }
    
    public void output()
    {
        System.out.printf("\n%8s%15s", maKhachHang, tenKhachHang);
    }
}