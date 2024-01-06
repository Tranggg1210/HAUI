package bai8;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class QuanLySanPham {
    private final Set<String> tenSanPhamDaSuDung;
    private ArrayList<NhanVien> danhSachNhanVien;

    public QuanLySanPham() {
        tenSanPhamDaSuDung = new HashSet<>();
    }

    public String layTenSanPhamMoi(ArrayList<NhanVien> danhSachNhanVien) {
        this.danhSachNhanVien = danhSachNhanVien;
        Random random = new Random();
        String tenSanPham;
        do {
            int index = random.nextInt(danhSachNhanVien.size());
            tenSanPham = danhSachNhanVien.get(index).getMaNV();
        } while (tenSanPhamDaSuDung.contains(tenSanPham));
        tenSanPhamDaSuDung.add(tenSanPham);
        return tenSanPham;
    }

    public String layTenPhoBienNhat() {
        int maxCount = 0;
        String tenPhoBien = null;
        for (String ten : tenSanPhamDaSuDung) {
            int count = 0;
            for (NhanVien nhanVien : danhSachNhanVien) {
                if (nhanVien.getTenNV().equals(ten)) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                tenPhoBien = ten;
            }
        }
        return tenPhoBien;
    }
}
