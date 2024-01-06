
package bai8;

import java.util.Scanner;

public class SanPham {
      static Scanner sc = new Scanner(System.in);
      private String tenSP;

    public SanPham() {
    }

    public SanPham( String tenSP) {
        this.tenSP = tenSP;
    }

    public String getTenSP() {
        return tenSP;
    }

    public void setTenSP(String tenSP) {
        this.tenSP = tenSP;
    }
     
       public void  printTitle()
    {
           System.out.printf("\n%8s", "Ten SP");
    }
    
    public void output()
    {
        System.out.printf("\n%8s%", tenSP);
    }
}
