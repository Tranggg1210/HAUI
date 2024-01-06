package Bai2;

import java.util.Scanner;

public class Bai17_NguyenThiTrang {
    public static void main(String[] args) {
//        Bài 17: Viết hoa chỉ các ký tự đầu từ trong một chuỗi. “Nguyễn Văn AbcNguyễn Văn Abc”
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập chuỗi: ");
        String[] s = scanner.nextLine().split(" ");
        StringBuilder kq = new StringBuilder();
        for(String tu: s){
            if(!tu.isEmpty()){
                char upperLetter = Character.toUpperCase(tu.charAt(0));
                kq.append(upperLetter).append(tu.substring(1)).append(" ");
            }
        }

        System.out.println("Chuỗi sau khi chuẩn hóa là: "+ kq.toString().trim());
    }
}
