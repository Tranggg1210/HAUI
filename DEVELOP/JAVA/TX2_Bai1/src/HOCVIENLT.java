public class HOCVIENLT extends HocVien {
    private double donGiaLT;
    private long soBH;

    // constructor
    public HOCVIENLT(){}
    public HOCVIENLT(String hoTen, String diaChi, LOAI_UU_TIEN loaiUuTien, LOAI_CHUONG_TRINH loaiChuongTrinh, long soBH, double donGiaLT) {
        super(hoTen, diaChi, loaiUuTien, loaiChuongTrinh);
        try
        {
           if(donGiaLT <= 10000)
           {
               throw new IllegalAccessException("Don gia lap trinh dang nho hon hoac bang 10000");

           }else{
              this.donGiaLT = donGiaLT;
           }
        }catch (IllegalAccessException e)
        {
            System.out.print("\t===> " + e.getMessage() +"\n");
        }
        this.soBH = soBH;
    }

    // getter
    public double getDonGiaLT()
    {
        return donGiaLT;
    }

    @Override
    public LOAI_UU_TIEN getLoaiUuTien() {
        return super.getLoaiUuTien();
    }

    // method
    @Override
    public void nhapThongTin()
    {
        super.nhapThongTin();
        do{
            System.out.print("\tSo buoi hoc: ");
            soBH = sc.nextLong();
        }while(soBH < 0);
        do{
            System.out.print("\tDon gia lap trinh: ");
            donGiaLT = sc.nextDouble();
        }while(donGiaLT < 0);
        sc.nextLine();
    }
    @Override
    public double tinhHocPhi()
    {
        double uuTien;
        if(loaiUuTien == LOAI_UU_TIEN.LOAI_1)
         {
             uuTien = 1000000;
         }else uuTien = 800000;
        return  (soBH*donGiaLT) - uuTien;
    }

    @Override
    public void printTitle()
    {
        super.printTitle();
        System.out.printf("%-15s%-15s%-15s", "So BH", "Don Gia", "Hoc Phi");
    }

    @Override
    public void printData()
    {
        super.printData();
        if(tinhHocPhi() < 0)
            System.out.printf("%-15s%-15s%-15s", soBH, donGiaLT, "Hoc phi am");
        else
            System.out.printf("%-15s%-15s%-15s", soBH, donGiaLT, String.format("%.0f",tinhHocPhi()));
    }

    public String toString()
    {
        return (
                tinhHocPhi() < 0 ? ("\n" + hoTen
                        + " ; " + diaChi
                        + " ; " + loaiUuTien
                        + " ; " + loaiChuongTrinh
                        + " ; Hoc phi am" ) :
                        "\n" + hoTen
                                + " ; " + diaChi
                                + " ; " + loaiUuTien
                                + " ; " + loaiChuongTrinh
                                + " ; " + String.format("%.0f",tinhHocPhi())
        );
    }
}
