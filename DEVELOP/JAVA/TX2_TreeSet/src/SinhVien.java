import java.util.Scanner;

public class SinhVien extends Nguoi implements Comparable<SinhVien>{
    public Scanner sc = new Scanner(System.in);
    private String lop;
    private String nganh;
    private Truong truong = new Truong();

    // constructor
    public SinhVien(){}
    public SinhVien(String ten, int tuoi, String gioiTinh, String lop, String nganh, String tenT, String diaChiT, String hieuTruong) {
        super(ten, tuoi, gioiTinh);
        if(lop.isBlank())
        {
            System.out.println("\n===> Lop hoc cua sinh vien dang rong!!!");
            do{
                System.out.println("\nNhap lop hoc cua sinh vien " + ten + " de bo sung: ");
                lop = sc.nextLine();
            }while(lop.isBlank());
            this.lop = lop;
        }else this.lop = lop;
        this.nganh = nganh;
        truong = new Truong(tenT, diaChiT, hieuTruong);
    }

// getter and setter

    public String getLop() {
        return lop;
    }

    public void setLop(String lop) {
        if(lop.isBlank())
        {
            System.out.println("\n===> Lop hoc cua sinh vien dang rong!!!");
            do{
                System.out.println("\nNhap lop hoc cua sinh vien " + ten + " de bo sung: ");
                lop = sc.nextLine();
            }while(lop.isBlank());
            this.lop = lop;
        }else this.lop = lop;
    }

    public String getNganh() {
        return nganh;
    }

    public void setNganh(String nganh) {
        this.nganh = nganh;
    }

    public Truong getTruong() {
        return truong;
    }

    public void setTruong(Truong truong) {
        this.truong = truong;
    }

    // toString
    @Override
    public String toString()
    {
        return (super.toString() + "; " + lop + "; " + nganh + truong.toString());
    }

    // output
    @Override
    public void printTitle()
    {
        super.printTitle();
        System.out.printf("%-15s%-15s","Lop", "Nganh");
        truong.printTitle();
    }
    @Override
    public void printData()
    {
        super.printData();
        System.out.printf("%-15s%-15s", lop, nganh);
        truong.printData();
    }

    // compareTo
    @Override
    public int compareTo(SinhVien a)
    {
        if(this.ten.compareTo(a.ten) < 0) return -1;
        else if(this.ten.compareTo(a.ten) == 0) return 0;
        else return 1;
    }
}
