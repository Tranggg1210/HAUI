package tx1;

import java.util.Comparator;
import java.util.ArrayList;
import java.util.Scanner;

public class TX1 {
    
    static Scanner sc = new Scanner(System.in);

    static ArrayList<ThueBaoTheoDungLuong> nhap() {
        ArrayList<ThueBaoTheoDungLuong> listTB = new ArrayList();
        int i = 1;
        do {
            ThueBaoTheoDungLuong t = new ThueBaoTheoDungLuong();
            System.out.printf("\n>>>> NHAP THONG TIN KHACH HANG DAT THUE BAO " + i + "(chu y: nhap ma thue bao bang * de thoat viec nhap du lieu) <<<<\n");
            t.nhap();
            if (t.getMaTB().equals("*")) {
                break;
            }
            i++;
            listTB.add(t);
        } while (true);
        return listTB;
    }

    static void xuat(ArrayList<ThueBaoTheoDungLuong> listTB) {
        if (!listTB.isEmpty()) {
            ThueBaoTheoDungLuong t = new ThueBaoTheoDungLuong();
            t.inTieuDe();
            for (ThueBaoTheoDungLuong item : listTB) {
                item.xuat();
            }
        } else {
            System.out.println("Khong co thue bao nao trong danh sach");
        }
    }

    static void sortByMaTB(ArrayList<ThueBaoTheoDungLuong> listTB) {
        System.out.print("\nBANG DANH SACH THONG TIN CAC THUE BAO THEO DUNG LUONG DUOC SAP XEP THEO CHIEU TANG DAN CUA MA TB");
        listTB.sort(Comparator.comparing(ThueBaoTheoDungLuong::getMaTB));
        xuat(listTB);
    }

    //Nhập vào mã thuê bao, tìm kiếm trong danh sách và hiển thị
//thông tin thuê bao có mã vừa nhập
    static void searchByMaTB(ArrayList<ThueBaoTheoDungLuong> listTB) {
        if (!listTB.isEmpty()) {
            String searchMaTB;
            int count = 0;
            System.out.print("\nNhap ma TB can tim: ");
            searchMaTB = sc.nextLine();
            for (ThueBaoTheoDungLuong item : listTB) {
                if (item.getMaTB().equals(searchMaTB)) {
                    count++;
                    break;
                }
            }
            if (count == 0) {
                System.out.println("Khong co thue bao can tim trong danh sach");
            } else {
                ThueBaoTheoDungLuong t = new ThueBaoTheoDungLuong();
                t.inTieuDe();
                for (ThueBaoTheoDungLuong item : listTB) {
                    if (item.getMaTB().equals(searchMaTB)) {
                        item.xuat();
                    }
                }
            }
        } else {
            System.out.println("Khong co thue bao nao trong danh sach");
        }
    }

    public static void main(String[] args) {
        ArrayList<ThueBaoTheoDungLuong> listTB = nhap();
        if (!listTB.isEmpty()) {
            System.out.print("\nBANG DANH SACH THONG TIN CAC THUE BAO THEO DUNG LUONG");
        }
        xuat(listTB);
        sortByMaTB(listTB);
        searchByMaTB(listTB);
    }
}
