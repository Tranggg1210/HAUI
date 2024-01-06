import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    // y 1
    static void fakeData(LinkedHashSet list)
    {
        SinhVien a = new SinhVien("Nguyen Thi Trang", 20, "Nu", "KTPM03", "KTPM");
        list.add(a);
        SinhVien b = new SinhVien("Le Thi Huyen", 20, "Nu", "KTPM01", "KTPM");
        list.add(b);
        SinhVien c = new SinhVien("Dinh Van Anh", 20, "Nam", "CNTT09", "CNTT");
        list.add(c);
    }

    static void output(LinkedHashSet list, String title)
    {
        if(list.isEmpty())
        {
            System.out.println("\n===> Danh sach rong!!!");
        }else{
            System.out.println("\n===== " + title + " =====");
            SinhVien a = new SinhVien();
            a.printTitle();
            Iterator lh = list.iterator();
            while (lh.hasNext())
            {
                SinhVien b = (SinhVien) lh.next();
                b.printData();
            }
        }
    }

    // y 2
    static void nhapDS(LinkedHashSet list)
    {
        int i = 1;
        while(true)
        {
            System.out.println("\n===== NHAP THONG TIN SINH VIEN CAN BO SUNG THU " + i + " (viec nhap ket thuc khi ten sv rong)");
            i++;
            String ten, gioiTinh, lop, nganh;
            int tuoi = -1;
            System.out.print("\tTen sv: ");
            ten = sc.nextLine();
            if(ten.isBlank()) break;
            try{
                do{
                    System.out.print("\tTuoi > 0: ");
                    tuoi = sc.nextInt();
                }while (tuoi <= 0);
            }catch (Exception e)
            {
                System.out.println("\n===> Sai dinh dang du lieu cua tuoi");
                e.getStackTrace();
                return;
            }
            sc.nextLine();
            System.out.print("\tGioi tinh: ");
            gioiTinh = sc.nextLine();
            System.out.print("\tLop: ");
            lop = sc.nextLine();
            System.out.print("\tNganh: ");
            nganh = sc.nextLine();
            SinhVien a = new SinhVien(ten, tuoi, gioiTinh, lop, nganh);
            list.add(a);
        }
        output(list, "DANH SACH SINH VIEN SAU KHI BO SUNG");
    }

    static void timSV(LinkedHashSet list)
    {
        if(list.isEmpty())
        {
            System.out.println("\n===> Danh sach rong!!!");
        }else{
            Iterator ls = list.iterator();
            int i = 0, count = 0;
            int maxTuoi = 0;
            while(ls.hasNext())
            {
                SinhVien a = (SinhVien) ls.next();
                if(i == 0)
                {
                    maxTuoi = a.getTuoi();
                    i++;
                }
                if(maxTuoi < a.getTuoi())
                {
                    maxTuoi = a.getTuoi();
                }
            }

            ls = list.iterator();
            while(ls.hasNext())
            {
                SinhVien a = (SinhVien) ls.next();
                if(maxTuoi == a.getTuoi())
                {
                    count++;
                }
            }
            if(count == 1) System.out.println("\n===> Khong co sinh vien nao co tuoi bang sinh vien lon tuoi nhat");
            else if(count > 1){
                ls = list.iterator();
                System.out.println("\n==== DANH SACH SINH VIEN CO TUOI BANG SINH VIEN LON TUOI NHAT ====");
                SinhVien c = new SinhVien();
                c.printTitle();
                while(ls.hasNext())
                {
                    SinhVien a = (SinhVien) ls.next();
                    if(maxTuoi == a.getTuoi())
                    {
                        a.printData();
                    }
                }
            }
        }
    }


    // y 3
    static void ghiFile(LinkedHashSet list)
    {
        try{
            FileWriter fw = new FileWriter("SV.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            Iterator ls = list.iterator();
            while(ls.hasNext())
            {
                SinhVien a = (SinhVien) ls.next();
                bw.write(a.toString());
            }
            bw.close();
            fw.close();
            System.out.println("\n====> Ghi du lieu thanh cong!!!");
        }catch (Exception e)
        {
            System.out.println("\n===> Loi, khong the ghi file");
            e.getStackTrace();
        }
    }
    static void docFile(LinkedHashSet list)
    {
        try{
            System.out.println("\n==== DU LIEU TRONG FILE SV.txt");
            FileReader fr = new FileReader("SV.txt");
            BufferedReader br = new BufferedReader(fr);
            String line = "";
            while((line = br.readLine()) != null)
            {
                System.out.println(line);
            }
            br.close();
            fr.close();
            System.out.println("\n====> Doc du lieu thanh cong!!!");
        }catch (Exception e)
        {
            System.out.println("\n===> Loi, khong the doc file");
            e.getStackTrace();
        }
    }


    public static void main(String[] args) {
        LinkedHashSet list = new LinkedHashSet();

        // y 1
        try{
            fakeData(list);
            output(list, "DANH SACH SINH VIEN VUA KHOI TAO");
        }catch (Exception e)
        {
            System.out.println("\n===> Loi o y 1! Kiem tra xem ban da fake dung dinh dang du lieu chua");
            e.getStackTrace();
        }

        // y2
        try{
            nhapDS(list);
            timSV(list);
        }catch (Exception e)
        {
            System.out.println("\n===> Loi o y 2! Kiem tra xem ban da nhap dung dinh dang du lieu chua");
            e.getStackTrace();
        }

        // y 3
        try{
            ghiFile(list);
            docFile(list);
        }catch (Exception e)
        {
            System.out.println("\n===> Loi o y 3! Kiem tra lai phan doc ghi file");
            e.getStackTrace();
        }
    }
}