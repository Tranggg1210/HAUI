public class Truong {
    private String ten;
    private String diaChi;
    private String hieuTruong;

    // contrustor
    public Truong(){}

    public Truong(String ten, String diaChi, String hieuTruong) {
        this.ten = ten;
        this.diaChi = diaChi;
        this.hieuTruong = hieuTruong;
    }

    // getter and setter

    public String getTen() {
        return ten;
    }

    public void setTenT(String ten) {
        this.ten = ten;
    }

    public String getDiaChi() {
        return diaChi;
    }

    public void setDiaChi(String diaChi) {
        this.diaChi = diaChi;
    }

    public String getHieuTruong() {
        return hieuTruong;
    }

    public void setHieuTruong(String hieuTruong) {
        this.hieuTruong = hieuTruong;
    }

    // toString
    public String toString()
    {
        return ("; " + ten + "; " + diaChi + "; " + hieuTruong);
    }

    // output
    public void printTitle()
    {
        System.out.printf("%-25s%-15s%-15s", "Ten Truong", "Dia Chi", "Hieu Truong");
    }

    public void printData()
    {
        System.out.printf("%-25s%-15s%-15s", ten, diaChi, hieuTruong);
    }
}
