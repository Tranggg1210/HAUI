package tx1;

public class ThueBaoTheoDungLuong extends ThueBao {

    private double dungLuong;

    // constructer
    public ThueBaoTheoDungLuong() {
    }

    public ThueBaoTheoDungLuong(double dungLuong, String maTB, String chuTB, String diaChi) {
        super(maTB, chuTB, diaChi);
        this.dungLuong = dungLuong;
    }
    
    @Override
    public void nhap()
    {
        super.nhap();
        if(super.getMaTB().equals("*")) return;
        System.out.print("\tDung luong: ");
        dungLuong = sc.nextDouble();
        sc.nextLine();
    }
    
    public double tinhTIenCuocThueBaoHangThang()
    {
        double cuocDL = dungLuong*40;
        if(cuocDL > mucTran) return mucTran+ tienTB;
        return dungLuong*40 + tienTB;
    } 
    
      @Override
    public void xuat()
    {
        super.xuat();
        System.out.printf("%15s%15s", dungLuong, tinhTIenCuocThueBaoHangThang());
    }
    
    public void inTieuDe()
    {
          System.out.printf("\n%8s%15s%15s%15s%15s","Ma TB",  "Chu TB", "Dia Chi", "Dung Luong", "Thanh Tien");
    }
}
