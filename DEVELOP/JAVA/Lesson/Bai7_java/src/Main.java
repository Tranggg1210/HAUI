import javax.swing.plaf.IconUIResource;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static TreeSet input(TreeSet<Integer> arr)
    {
        int a;
        do{
            System.out.print("\nNhập số nguyên (nhập -1 để kết thúc việc nhập dữ liệu): ");
            a = sc.nextInt();
            arr.add(a);
        }while(a != -1);
        return arr;
    }

    static void output(TreeSet<Integer> arr)
    {
        for (int item:
             arr) {
            System.out.print(item + "\t");
        }
    }

    static void search(TreeSet<Integer> arr)
    {
        System.out.print("\nNhập giá trị cần tìm kiếm: ");
        int k, count = 0;
        k = sc.nextInt();
        for (int item:arr) {
            if(item == k)
            {
                count++;
                break;
            }
        }
        if(count == 0)
        {
            System.out.print("\nKhông có phần tử nào trong TreeSet có giá trị bằng " + k);
        }else{
            System.out.print("\nTrong TreeSet có giá trị bằng " + k);
        }

    }

    static void delete(TreeSet<Integer> arr)
    {
        System.out.print("\nNhập giá trị cần xóa: ");
        int k, count = 0;
        k = sc.nextInt();
        for (int item:arr) {
            if(item == k)
            {
                count++;
                break;
            }
        }
        if(count == 0)
        {
            System.out.print("\nKhông có phần tử nào trong TreeSet có giá trị bằng " + k);
        }else{
            arr.remove(k);
            System.out.println("\nTreeSet sau khi xóa phần tử " + k + ": ");
            output(arr);
        }

    }

    public static void main(String[] args) {
        TreeSet<Integer> arrNumber = new TreeSet<Integer>();
        input(arrNumber);
        System.out.println("\nTreeSet vừa nhập là: ");
        output(arrNumber);
        search(arrNumber);
        delete(arrNumber);
    }
}