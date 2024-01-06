package Bai3;
public class KhachHangVN extends KhachHang {
    private String doiTuong;
    private float dinhMuc;

    public KhachHangVN() {}
    public KhachHangVN(long maKH, String hoTen, Date ngayRaDon, int soLuong, long donGia, String doiTuong, float dinhMuc) {
        super(maKH, hoTen, ngayRaDon, soLuong, donGia);
        this.doiTuong = doiTuong;
        this.dinhMuc = dinhMuc;
    }

    @Override
    public double thanhTien()
    {
        if(getSoLuong() <= dinhMuc)
            return getSoLuong() * getDonGia();
        return getSoLuong() * getDonGia() * dinhMuc + (getSoLuong() - dinhMuc)*getDonGia()*2.5;
    }

    public void input()
    {
        super.input();
        sc.nextLine();
        System.out.print("\tĐối tượng: ");
        doiTuong = sc.nextLine();
        System.out.print("\tĐịnh mức: ");
        dinhMuc = sc.nextFloat();
    }

    public void output()
    {
        super.output();
        System.out.printf("%15s%15s%15s", doiTuong, dinhMuc, thanhTien());
    }
}
