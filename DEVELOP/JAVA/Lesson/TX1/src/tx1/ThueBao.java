package tx1;

import java.util.Scanner;

public class ThueBao implements NhapXuat{
    static Scanner sc = new Scanner(System.in);
    private String maTB;
    private String chuTB;
    private String diaChi;
    
    
    //constructor
    public ThueBao() {
    }

    public ThueBao(String maTB, String chuTB, String diaChi) {
        this.maTB = maTB;
        this.chuTB = chuTB;
        this.diaChi = diaChi;
    }
    
    //getter
     public String getMaTB() {
        return maTB;
    }

    @Override
    public void nhap() {
        System.out.print("\tMa thue bao: ");
        maTB = sc.nextLine();
        if(maTB.equals("*")) return;
        System.out.print("\tChu thue bao: ");
        chuTB = sc.nextLine();
        System.out.print("\tDia chi: ");
        diaChi = sc.nextLine();
    }

    @Override
    public void xuat() {
        System.out.printf("\n%8s%15s%15s",maTB, chuTB, diaChi);
    }
    
    

}
