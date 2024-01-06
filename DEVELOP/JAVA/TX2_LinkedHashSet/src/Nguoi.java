public class Nguoi {
    protected String ten;
    protected int tuoi;
    protected String gioiTinh;

    // contrustor
    public Nguoi() {}

    public Nguoi(String ten, int tuoi, String gioiTinh) {
       try{
           this.ten = ten;
           if(tuoi <= 0)
           {
               throw new IllegalAccessException("Tuoi <= 0");
           }else this.tuoi = tuoi;
           this.gioiTinh = gioiTinh;
       }catch (IllegalAccessException e)
       {
           System.out.println("\n===> Loi: " + e.getMessage());
           e.getStackTrace();
       }
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
        try{
            if(tuoi <= 0)
            {
                throw new IllegalAccessException("Tuoi <= 0");
            }else this.tuoi = tuoi;
        }catch (IllegalAccessException e)
        {
            System.out.println("\n===> Loi: " + e.getMessage());
            e.getStackTrace();
        }
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
        System.out.printf("%-25s%-15s%-15s", "Ten SV", "Tuoi", "Gioi Tinh");
    }

    public void printData()
    {
        System.out.printf("\n%-25s%-15s%-15s", ten, tuoi, gioiTinh);
    }
}
