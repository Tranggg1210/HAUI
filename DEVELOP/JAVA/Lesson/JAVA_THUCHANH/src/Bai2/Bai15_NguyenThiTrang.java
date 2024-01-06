package Bai2;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Bai15_NguyenThiTrang {
    public static void main(String[] args) {
//        Bài 15: Tìm ra những ký tự có tần suất xuất hiện lớn nhất trong một chuỗi.
//        “everybody”  e,y
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nhập vào chuỗi cần kiểm tra: ");
        String str = scanner.nextLine();
        Map<Character, Integer> tanSuat = new HashMap<>();

        for (char c : str.toCharArray()){
            if(!Character.isLetterOrDigit(c)){
                continue;
            }

            if(tanSuat.containsKey(c)){
                tanSuat.put(c,tanSuat.get(c)+1);
            }else{
                tanSuat.put(c,1);
            }
        }

        int maxTanSuat = 0;
        for(int count : tanSuat.values()){
            if(count > maxTanSuat){
                maxTanSuat = count;
            }
        }
        System.out.println("Tần suất hiện lớn nhất là: "+ maxTanSuat);
        System.out.println("Các ký tự có tần xuất xuất hiện lớn nhất là: ");
        for(Map.Entry<Character,Integer> entry : tanSuat.entrySet()){
            if(entry.getValue() == maxTanSuat){
                System.out.print(entry.getKey() + " ");
            }
        }
    }
}
