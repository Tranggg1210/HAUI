public class Program {
    public static void main(String[] args) {
        HoaDon hd1 = new HoaDon();
        hd1.input();
        System.out.println("\n>>> BẢNG HÓA ĐƠN VỪA NHẬP");
        hd1.output();
        System.out.println("\n\n>>> BẢNG HÓA ĐƠN SAU KHI SẮP XẾP THEO TÊN");
        hd1.sortByName();
        hd1.output();
    }
}
