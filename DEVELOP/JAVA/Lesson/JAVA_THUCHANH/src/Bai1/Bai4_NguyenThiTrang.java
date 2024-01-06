package Bai1;
import java.util.Scanner;

public class Bai4_NguyenThiTrang {
    static float factorial(int n) {
        float numberOfFactorial = 1;
        for (int i = n; i >= 1; i--) {
            numberOfFactorial *= i;
        }
        return numberOfFactorial;
    }

     static double C(int m, int n) {
        return (factorial(m) / (factorial(n) * factorial(m - n)));
    }

    public static void main(String[] args) {
//        Bài 4: Viết chương trình tính C(m,n)
//        C(m, n) = m! / (n! * (m - n)!)
        Scanner scanner = new Scanner(System.in);
        int m, n;
        do {
            System.out.print("Nhập hai số m,n với m,n >= 0 và m >= n: ");
            m = scanner.nextInt();
            n = scanner.nextInt();
        } while (m < 0 || n < 0 || m < n);
        System.out.println("Giá trị biểu thức C(" + m + "," + n + ") là: " + C(m,n));
    }
}










