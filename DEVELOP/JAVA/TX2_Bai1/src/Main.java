import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Iterator;

public class Main {
    static void fakeData(HashSet listStudents)
    {
        HOCVIENLT a = new HOCVIENLT("Nguyen Thi Trang", "Hung Yen", LOAI_UU_TIEN.LOAI_1, LOAI_CHUONG_TRINH.LAP_TRINH, 28, 200000);
        listStudents.add(a);
        HOCVIENLT b = new HOCVIENLT("Le Thi Lan", "Ha Noi", LOAI_UU_TIEN.LOAI_2, LOAI_CHUONG_TRINH.LAP_TRINH, 24, 600000);
        listStudents.add(b);
        HOCVIENLT c = new HOCVIENLT("Luong Hoang Duong", "Ha Nam", LOAI_UU_TIEN.LOAI_2, LOAI_CHUONG_TRINH.LAP_TRINH, 20, 500000);
        listStudents.add(c);
    }

    static void printList(HashSet listStudents, boolean printTitle)
    {
        if(listStudents.isEmpty())
        {
            System.out.println("\n===> Danh sach rong!!!");
        }else{
            Iterator list = listStudents.iterator();
            HOCVIENLT b = new HOCVIENLT();
            if(printTitle)
                System.out.println("\n===== DANH SACH HOC VIEN LAP TRINH VUA TAO =====");
            b.printTitle();
            while(list.hasNext())
            {
                HOCVIENLT a = (HOCVIENLT) list.next();
                a.printData();
            }
        }

    }

    static void nhapBoSungVaInUTL1(HashSet listStudent)
    {
        boolean donGiaLTHL = false;
        int i = 1;
         do{
             System.out.println("\n==== NHAP THONG TIN HOC VIEN CAN BO SUNG THU " + i + "(viec nhap ket thuc khi don gia lap trinh bang 0)");
             HOCVIENLT a = new HOCVIENLT();
             a.nhapThongTin();
             if(a.getDonGiaLT() == 0) donGiaLTHL = true;
             listStudent.add(a);
         }while (!donGiaLTHL);
        System.out.println("\n===== DANH SACH HOC VIEN LAP TRINH SAU KHI BO SUNG HOC VIEN =====");
        printList(listStudent, false);


        // in cac hoc vien uu tien loai 1
        int count = 0;
        Iterator list = listStudent.iterator();
        while(list.hasNext())
        {
            HOCVIENLT b = (HOCVIENLT) list.next();
            if(b.getLoaiUuTien().name() == LOAI_UU_TIEN.LOAI_1.name())
            {
                count++;
                break;
            }
        }
        if(count == 0) System.out.println("\n===> Khong co hoc vien uu tien loai 1 trong danh sach");
        else{
            System.out.println("\n===== DANH SACH HOC VIEN LAP TRINH UU TIEN LOAI 1 =====");
            HOCVIENLT c = new HOCVIENLT();
            c.printTitle();
            while(list.hasNext())
            {
                HOCVIENLT b = (HOCVIENLT) list.next();
                if(b.getLoaiUuTien().name() == LOAI_UU_TIEN.LOAI_1.name())
                {
                    b.printData();
                }
            }
        }
    }

    // y 3
    static void ghiFile(HashSet listStudents)
    {
        try{
            FileWriter fw = new FileWriter("hocVienLT.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            Iterator list  = listStudents.iterator();
            while (list.hasNext()){
                HOCVIENLT a = (HOCVIENLT) list.next();
                bw.write(a.toString());
            }
            bw.close();
            fw.close();
            System.out.println("\nIn file thanh cong");
        }catch (Exception e)
        {
            System.out.println("\nLoi! Khong in duoc file");
        }
    }

    static void docFile(HashSet listStudents)
    {
        try{
            FileReader fr = new FileReader("hocVienLT.txt");
            BufferedReader br = new BufferedReader(fr);
            String line = "";
            System.out.println("\n===== DU LIEU TRONG FILE hocVienLt.txt ");
            while((line = br.readLine()) != null)
            {
                System.out.println(line);
            }
            fr.close();
            br.close();
            System.out.println("\nDoc file thanh cong");
        }catch (Exception e)
        {
            System.out.println("\nLoi! Khong doc duoc file");
        }
    }

    public static void main(String[] args) {
        // tao hashset
        HashSet listStudents = new HashSet();

        // y 1
        fakeData(listStudents);
        printList(listStudents, true);

        // y2
        nhapBoSungVaInUTL1(listStudents);

        // y3
        ghiFile(listStudents);
        docFile(listStudents);
    }
}