package Bai1;

import java.sql.SQLOutput;
import java.util.Scanner;

public class NhanVien {
    Scanner sc = new Scanner(System.in);
    private String maNV;
    private int soSP;

    public String getMaNV() {
        return maNV;
    }

    public int getSoSP() {
        return soSP;
    }

    public void setMaNV(String maNV)
    {
        if(maNV.trim() != "")
            this.maNV = maNV;
        System.out.println("Mã nhân viên không được trống");
        return;
    }

    public void setSoSP(int soSP) {
        if(soSP != 0)
            this.soSP = soSP;
        System.out.println("Số sản phẩm phải lớn hơn 0");
        return;
    }

    public NhanVien() {}
    public NhanVien(String maNV, int soSP) {
        this.maNV = maNV;
        this.soSP = soSP;
    }
    public boolean coVuotChuan()
    {
        if(soSP > 500) return true;
        return false;
    }
    public String getTongKet()
    {
        if(coVuotChuan()) return "Vượt";
        return "";
    }
    public double getLuong()
    {
        if(coVuotChuan()) return ((soSP-500)*30000 + 500*20000);
        return soSP*20000;
    }

    public String toString()
    {
        return maNV + " - " + soSP;
    }
    public void xuaTieuDe()
    {
        System.out.printf("%8s%15s%15s%15s", "Mã NV", "Số Sản Phẩm", "Lương", "Tổng kết");
    }
    public void inDL()
    {
        String tk = "";
        if(getTongKet() == "") tk = "Không vượt";
        else tk = getTongKet();
        System.out.printf("\n%8s%15s%15s%15s", maNV, soSP, String.format("%.0f", getLuong()), tk);
    }

    public void input()
    {
       do{
           System.out.print("\tMã nhân viên(lưu ý: mã nv không trống): ");
           maNV = sc.nextLine();
       }while(maNV.trim() == "");
       do{
           System.out.print("\tSố sản phẩm của nv(lưu ý: số sp > 0):  ");
           soSP = sc.nextInt();
       }while(soSP <= 0);
    }
}
