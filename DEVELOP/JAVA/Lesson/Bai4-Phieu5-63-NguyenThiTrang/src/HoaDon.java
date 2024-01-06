import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class HoaDon {

    Scanner sc = new Scanner(System.in);
    private String maHD;
    private String ngayBan;
    private KhachHang kh1 = new KhachHang();
    private Hang[] h;
    int n;

    // constructer
    public HoaDon(){}
    public HoaDon(Scanner sc, String maHD, String ngayBan, KhachHang kh1, Hang[] h, int n) {
        this.sc = sc;
        this.maHD = maHD;
        this.ngayBan = ngayBan;
        this.kh1 = kh1;
        this.h = h;
        this.n = n;
    }

    // nhập thông tin của hóa đơn
    public void input()
    {
        System.out.println("===== NHẬP THÔNG TIN HÓA ĐƠN =====");
        System.out.print("Nhập mã hóa đơn: ");
        maHD = sc.nextLine();
        System.out.print("Nhập ngày bán: ");
        ngayBan = sc.nextLine();
        kh1.input();
        do{
            System.out.print("Nhập số lượng hàng hóa của hóa đơn n > 0: ");
            n = sc.nextInt();
        }while(n < 1);

        // gán số lượng mặc định cho n
        h = new Hang[n];
        for (int i = 0; i < n; i++) {
            h[i] = new Hang();
        }

        //Nhập giá trị cho mảng hàng hóa
        for(int i = 0;  i < n; i++)
        {
            System.out.println("Nhập thông tin của mặt hàng thứ " + (i+1));
            h[i].input();
        }
    }

    public double sumIntoMoney()
    {
        double sum = 0;
        for (Hang i: h) {
            sum += i.intoMoney();
        }
        return sum;
    }

    public double total()
    {
        double sum = 0;
        for (Hang i :h) {
            sum += i.getSoLuong();
        }
        return sum;
    }

    public void output()
    {
        System.out.printf("\t%-1s%-1s%26s%1s", "Mã HĐ: ", maHD, "Ngày bán: ", ngayBan);
        kh1.output();
        h[1].printTitle();
        for (int i = 0; i < n; i++) {
            h[i].printData();
        }
        System.out.printf("\n%8s%29s%15s", "Tổng tiền", total(), sumIntoMoney());
    }

    public void sortByName()
    {
        Arrays.sort(h, Comparator.comparing(Hang::getTenHang));
    }
}
