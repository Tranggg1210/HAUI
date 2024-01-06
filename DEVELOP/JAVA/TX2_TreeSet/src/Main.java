import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static void fakeData(TreeSet treeStudents)
    {
        SinhVien a = new SinhVien("Nguyen Thi Trang", 20, "Nu", "KTPM03", "KTPM", "DHCNHN", "Ha Noi", "Nguyen Van A");
        treeStudents.add(a);
        SinhVien b = new SinhVien("Duong Van An", 20, "Nam", "CNTT10", "CNTT", "DHCNHN", "Ha Noi", "Nguyen Van A");
        treeStudents.add(b);
        SinhVien c = new SinhVien("Nguyen Thi Lan", 20, "Nu", "KHMT02", "KHMT", "DHCNHN", "Ha Noi", "Nguyen Van A");
        treeStudents.add(c);
    }

    static void Output(TreeSet treeStudents, String title)
    {
        if(treeStudents.isEmpty())
        {
            System.out.println("\n===> Danh sach rong!!!");
        }else{
            System.out.println("\n===== " + title +"  =====");
            Iterator list = treeStudents.iterator();
            SinhVien a = new SinhVien();
            a.printTitle();
            while(list.hasNext())
            {
                SinhVien b = (SinhVien) list.next();
                b.printData();
            }
        }
    }

    // y 2
    static void nhapDS(TreeSet treeStudents)
    {
        int i = 1;
        do{
            String tenSV,gioiTinh, lop, nganh, tenT, diaChiT, hieuTruong;
            int tuoi;
            System.out.println("\n==== NHAP THONG TIN SINH VIEN THU " + i + " CAN BO SUNG VAO DANH SACH (viec nhap se dung khi nhap nganh rong)");
            System.out.print("\tTen sv: ");
            tenSV = sc.nextLine();
            System.out.print("\tTuoi: ");
            tuoi = sc.nextInt();
            sc.nextLine();
            System.out.print("\tGioi tinh: ");
            gioiTinh = sc.nextLine();
            System.out.print("\tLop: ");
            lop = sc.nextLine();
            System.out.print("\tNganh: ");
            nganh = sc.nextLine();
            if(nganh.isBlank()) break;
            System.out.print("\tTen truong: ");
            tenT = sc.nextLine();
            System.out.print("\tDia chi truong: ");
            diaChiT = sc.nextLine();
            System.out.print("\tHieu truong: ");
            hieuTruong = sc.nextLine();
            SinhVien a = new SinhVien(tenSV, tuoi, gioiTinh, lop, nganh, tenT, diaChiT, hieuTruong);
            treeStudents.add(a);
        }while(true);
        Output(treeStudents, "DANH SACH SINH VIEN SAU KHI BO SUNG SINH VIEN");
    }

    static void laySVTuNganh(TreeSet treeStudents)
    {
        String nganh;
        int count = 0;
        do{
            System.out.print("\nNhap nganh ban can tim(nganh khong rong): ");
            nganh = sc.nextLine();
        }while(nganh.isBlank());
        Iterator list = treeStudents.iterator();
        while(list.hasNext())
        {
            SinhVien sv = (SinhVien) list.next();
            if(sv.getNganh().equalsIgnoreCase(nganh))
            {
                count++;
                break;
            }
        }
        if(count == 0)
            System.out.println("\n===> Khong co sinh vien nao thuoc nganh " + nganh.toLowerCase() + " trong danh sach");
        else
        {
            System.out.println("\n===== DANH SACH SINH VIEN THUOC NGANH " + nganh.toUpperCase() + " =====");
            SinhVien a = new SinhVien();
            a.printTitle();
            list = treeStudents.iterator();
            while(list.hasNext())
            {
                SinhVien sv = (SinhVien) list.next();
                if(sv.getNganh().equalsIgnoreCase(nganh))
                {
                    sv.printData();
                }
            }
        }

    }

    // y3
    static void ghiFile(TreeSet treeStudents)
    {
        try{
            FileWriter fw = new FileWriter("SinhVien.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            Iterator list = treeStudents.iterator();
            while(list.hasNext())
            {
                SinhVien a = (SinhVien) list.next();
                bw.write(a.toString());
            }
            System.out.println("\n===> Ghi file thanh cong");
            bw.close();
            fw.close();
        }catch (Exception e)
        {
            System.out.println("\n===> Loi, khong the ghi file ");
            e.printStackTrace();
        }
    }

    static void docFile(TreeSet treeStudents)
    {
        try{
            System.out.println("\n===> Doc file thanh cong");
            System.out.println("==== DU LIEU TRONG FILE LA:");
            FileReader fr = new FileReader("SinhVien.txt");
            BufferedReader br = new BufferedReader(fr);
            String line = "";
            while((line = br.readLine()) != null)
            {
                System.out.println(line);
            }
            fr.close();
            br.close();
        }catch (Exception e)
        {
            System.out.println("\n===> Loi, khong the doc file");
        }
    }

    public static void main(String[] args) {

           // y 1
           TreeSet treeStudents = new TreeSet();
           try {
               fakeData(treeStudents);
               Output(treeStudents, "DANH SACH SINH VIEN VUA KHOI TAO");
           }catch (Exception e) {
               System.out.println("\n===> Loi o y1, kiem tra xem ban da fake dung dinh dang du lieu chua");
               return;
           }

           // y 2
            try {
                nhapDS(treeStudents);
                laySVTuNganh(treeStudents);
            }catch (Exception e) {
                System.out.println("\n===> Loi o y2, kiem tra xem ban da nhap dung dinh dang du lieu chua");
                return;
            }


           // y 3
            try {
                ghiFile(treeStudents);
                docFile(treeStudents);
            }catch (Exception e) {
                System.out.println("\n===> Loi o y3, kiem tra xem phan doc ghi file");
                return;
            }
    }
}