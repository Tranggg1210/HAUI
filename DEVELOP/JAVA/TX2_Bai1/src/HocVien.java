import java.util.Scanner;

public abstract class HocVien {
    public static Scanner sc = new Scanner(System.in);
    protected String hoTen;
    protected String diaChi;
    protected LOAI_UU_TIEN loaiUuTien;
    protected LOAI_CHUONG_TRINH loaiChuongTrinh;

    // constructor
    public HocVien(){}
    public HocVien(String hoTen, String diaChi, LOAI_UU_TIEN loaiUuTien, LOAI_CHUONG_TRINH loaiChuongTrinh) {
        this.hoTen = hoTen;
        this.diaChi = diaChi;
        this.loaiUuTien = loaiUuTien;
        if(loaiChuongTrinh.name() != LOAI_CHUONG_TRINH.LAP_TRINH.name())
        {
            System.out.print("\t===> Xin loi ban, ben minh chi co loai chuong trinh lap trinh thui!!!");
        }
        this.loaiChuongTrinh = loaiChuongTrinh;
    }

    // getter


    public LOAI_UU_TIEN getLoaiUuTien() {
        return loaiUuTien;
    }

    // method
    public abstract double tinhHocPhi();

    public void nhapThongTin()
    {
        System.out.print("\tHo ten: ");
        hoTen = sc.nextLine();
        System.out.print("\tDia chi: ");
        diaChi = sc.nextLine();
        String loaiUT;
        boolean loaiUTHopLe = false;
        do{

            System.out.printf("\tLoai uu tien (loai 1 hoac loai 2): ");
            loaiUT = sc.nextLine();
            if(loaiUT.isBlank()) System.out.println("===> Loai uu tien khong duoc rong!!!\n");
            else{
                try{
                    LOAI_UU_TIEN uuTien = LOAI_UU_TIEN.valueOf("LOAI_" + loaiUT.charAt(loaiUT.length() - 1));
                    loaiUTHopLe = true;
                    if(loaiUTHopLe)
                    {
                        loaiUuTien = uuTien;
                    }
                }catch (IllegalArgumentException e)
                {
                    System.out.print("\t===> Loai uu tien khong hop le\n");
                }
            }
        }while(!loaiUTHopLe);
        String loaiCT;
        boolean loaiCTHL = false;
        do{
            System.out.print("\tLoai chuong trinh (đo hoa hoac lap trinh): ");
            loaiCT = sc.nextLine();
            if(loaiCT.isBlank()) System.out.print("\t===> Loai uu tien khong duoc rong!!!\n");
            else {
                try{
                    LOAI_CHUONG_TRINH loaiCTD = LOAI_CHUONG_TRINH.valueOf(loaiCT.trim().replaceAll("\\s+", "_").toUpperCase());
                    if(loaiCTD.name() == LOAI_CHUONG_TRINH.LAP_TRINH.name())
                    {
                        loaiCTHL = true;
                        if(loaiCTHL) loaiChuongTrinh = LOAI_CHUONG_TRINH.LAP_TRINH;
                    }else{
                        System.out.print("\t===> Xin loi ban, ben minh chi co loai chuong trinh lap trinh thui!!!\n");
                    }
                }catch (IllegalArgumentException e)
                {
                    System.out.print("\t===> Loai chuong trinh khong hop le\n");
                }
            }
        }while(!loaiCTHL);

    }


    public String inThongTin()
    {
        return (
                "\tHo ten: " + hoTen
                + "\nDia chi: " + diaChi
                + "\nLoai uu tien: " + loaiUuTien
                + "\n Loai chuong trinh: " + loaiChuongTrinh
                + "\nHoc phi: " + tinhHocPhi()
                );
    }

    public void printTitle()
    {
        System.out.printf("%-30s%-15s%-15s%-15s","Ho ten", "Dia chi", "Loai UT", "Loai CT");
    }
    public void printData(){
        System.out.printf("\n%-30s%-15s%-15s%-15s", hoTen, diaChi, loaiUuTien, loaiChuongTrinh);
    }
}
