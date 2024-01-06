import java.util.Scanner;

public class Hang {
    Scanner sc = new Scanner(System.in);
    private String tenHang;
    private float donGia;
    private int soLuong;

    public Hang(){}
    public Hang(String tenHang, float donGia, int soLuong) {
        this.tenHang = tenHang;
        this.donGia = donGia;
        this.soLuong = soLuong;
    }
    public int getSoLuong() {
        return soLuong;
    }
    public String getTenHang() {
        return tenHang;
    }

    public String toString()
    {
        return (
                    "\n" + tenHang + "\t" + donGia + "\t" + soLuong + "\t" + donGia * soLuong
                );
    }
    public void input()
    {
        System.out.print("\tTên hàng: ");
        tenHang = sc.nextLine();
        System.out.print("\tĐơn giá: ");
        donGia = sc.nextFloat();
        System.out.print("\tSố lượng: ");
        soLuong = sc.nextInt();
    }

    public double intoMoney()
    {
        return donGia * soLuong;
    }
    static void printTitle()
    {
        System.out.printf("\n%8s%15s%15s%15s", "Tên hàng", "Đơn giá", "Số lượng", "Thành tiền");
    }
    public void printData()
    {
        System.out.printf("\n%8s%15s%15s%15s", tenHang, donGia, soLuong, intoMoney());
    }

}
