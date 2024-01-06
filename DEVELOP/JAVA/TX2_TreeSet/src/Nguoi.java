public class Nguoi {
    protected String ten;
    protected int tuoi;
    protected String gioiTinh;

    // constructor
    public Nguoi(){}
    public Nguoi(String ten, int tuoi, String gioiTinh)
    {
        this.ten = ten;
        this.tuoi  = tuoi;
        this.gioiTinh = gioiTinh;
    }

    // getter and setter

    public String getTen() {
        return ten;
    }

    public void setTen(String ten) {
        this.ten = ten;
    }

    public int getTuoi() {
        return tuoi;
    }

    public void setTuoi(int tuoi) {
        this.tuoi = tuoi;
    }

    public String getGioiTinh() {
        return gioiTinh;
    }

    public void setGioiTinh(String gioiTinh) {
        this.gioiTinh = gioiTinh;
    }

    // toString
    public String toString()
    {
        return ("\n" + ten + "; " + tuoi + "; " + gioiTinh);
    }

    // output

    public void printTitle()
    {
        System.out.printf("%-25s%-15s%-15s", "Ten SV", "Tuoi SV", "Gioi Tinh");
    }
    public void printData()
    {
        System.out.printf("\n%-25s%-15s%-15s", ten, tuoi, gioiTinh);
    }
}
