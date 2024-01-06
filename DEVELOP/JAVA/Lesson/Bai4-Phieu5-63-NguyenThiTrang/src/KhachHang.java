import java.util.Scanner;

public class KhachHang {
    Scanner sc = new Scanner(System.in);
    private String hoTen;
    private String diaChi;
    public void input()
    {
        System.out.print("Nhập họ tên khách hàng: ");
        hoTen = sc.nextLine();
        System.out.print("Nhập địa chỉ của khách hàng: ");
        diaChi = sc.nextLine();
    }

    public void output()
    {
        System.out.printf("\n\t%-1s%-1s%15s%1s", "Khách hàng: ", hoTen, "Địa chỉ: ", diaChi);
    }
    public String toString()
    {
        return (
                "Họ tên: " + hoTen
                        + "\t\tĐịa chỉ: " + diaChi
        );
    }
}
