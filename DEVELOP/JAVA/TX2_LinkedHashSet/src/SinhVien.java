public class SinhVien extends Nguoi{
    private String lop;
    private String nganh;

    // contrustor
    public SinhVien(){}
    public SinhVien(String ten, int tuoi, String gioiTinh, String lop, String nganh) {
        super(ten, tuoi, gioiTinh);
        this.lop = lop;
        this.nganh = nganh;
    }

    // getter and setter
    public String getLop() {
        return lop;
    }

    public void setLop(String lop) {
        this.lop = lop;
    }

    public String getNganh() {
        return nganh;
    }

    public void setNganh(String nganh) {
        this.nganh = nganh;
    }

    // toString
    public String toString()
    {
        return (super.toString() + "; " + lop + "; " + nganh);
    }

    // output
    @Override
    public void printTitle()
    {
        super.printTitle();
        System.out.printf("%-15s%-15s", "Lop", "Nganh");
    }

    @Override
    public void printData()
    {
        super.printData();
        System.out.printf("%-15s%-15s", lop, nganh);
    }

}
