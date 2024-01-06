package Bai3;

import java.sql.SQLOutput;
import java.util.Scanner;

public class Date {
    Scanner sc = new Scanner(System.in);
    private short ngay;
    private short thang;
    private short nam;

    public Date() {}
    public Date(short ngay, short thang, short nam) {
        this.ngay = ngay;
        this.thang = thang;
        this.nam = nam;
    }
    public String toString()
    {
        return ngay + "/" + thang + "/" + nam;
    }

    public short getNgay() {
        return ngay;
    }

    public void setNgay(short ngay) {
        this.ngay = ngay;
    }

    public short getThang() {
        return thang;
    }

    public void setThang(short thang) {
        this.thang = thang;
    }

    public short getNam() {
        return nam;
    }

    public void setNam(short nam) {
        this.nam = nam;
    }

    public void input()
    {
        do{
            System.out.print("\tNgày ra hóa đơn: ");
            ngay = sc.nextShort();
            System.out.print("\tTháng ra hóa đơn: ");
            thang = sc.nextShort();
            System.out.print("\tNăm ra hóa đơn: ");
            nam = sc.nextShort();
            if(ngay > 31) System.out.println("\t\t>>>Không có ngày nào lớn hơn ngày 31");
            if(thang == 2 && ngay > 29) System.out.println("\t\t>>>Tháng hai không có ngày nào lớn hơn 29");
            if(thang > 12) System.out.println("\t\t>>>Không có tháng nào lớn hơn tháng 12");
            if(ngay <= 0 || thang <= 0 || nam <= 0) System.out.println("\t\t>>>Không có ngày, tháng, năm nào nhỏ hơn không");
        }while(ngay <= 0 || thang <= 0 || nam <= 0 ||
                thang > 12 || ngay > 31 || (thang == 2 && ngay > 29)
        );
    }
    public void output()
    {
        System.out.printf("%15s", ngay + "/" + thang + "/" + nam);
    }
}
