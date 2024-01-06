package Bai3;

public class KhachHangNN extends KhachHang{
    private String quocTich;

    public KhachHangNN() {}

    public KhachHangNN(long maKH, String hoTen, Date ngayRaDon, int soLuong, long donGia, String quocTich) {
        super(maKH, hoTen, ngayRaDon, soLuong, donGia);
        this.quocTich = quocTich;
    }
    public String getQuocTich() {
        return quocTich;
    }

    public void setQuocTich(String quocTich) {
        this.quocTich = quocTich;
    }
    @Override
    public double thanhTien()
    {
        return getSoLuong()*getDonGia();
    }
    public void input()
    {
        super.input();
        sc.nextLine();
        System.out.print("\tQuốc tịch: ");
        quocTich = sc.nextLine();
    }
    public void output()
    {
        super.output();
        System.out.printf("%15s%15s", quocTich, thanhTien());
    }
}
