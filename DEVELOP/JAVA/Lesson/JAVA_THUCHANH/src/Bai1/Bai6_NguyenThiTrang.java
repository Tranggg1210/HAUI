package Bai1;

import java.util.Scanner;

public class Bai6_NguyenThiTrang {
    static boolean checkPrime(int n)
    {
        if(n < 2) return false;
        else {
            for(int i = 2; i <= Math.sqrt(n); i++)
                if(n%i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
//        Bài 6: Viết chương trình kiểm tra một số có phải là nguyên tố.
//        - Mảng 1 chiều:
        Scanner scanner = new Scanner(System.in);
        int n;
        int[] arr;
        do{
            System.out.print("Nhập số lượng phần tử của mảng: ");
            n = scanner.nextInt();
        }while(n < 1);
        arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            System.out.print("Nhập a[" + (i+1) + "]: ");
            arr[i] = scanner.nextInt();
        }
        for(int i = 0; i < n; i++)
            if(checkPrime(arr[i]))
                System.out.println("Phần tử thứ " + (i) + " có giá trị " + arr[i] + " là một số nguyên tố");
            else  System.out.println("Phần tử thứ " + (i) + " có giá trị " + arr[i] + " KHÔNG PHẢI là một số nguyên tố");
    }
}
