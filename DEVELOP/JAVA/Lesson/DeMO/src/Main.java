import java.util.*;

public class Main {
    static void output(HashMap<Integer, String> hashMap)
    {
        Set<Integer> keySet = hashMap.keySet();
        for (String value : hashMap.values()) {
            System.out.println(value + "\t");
        }
    }
    public static void main(String[] args) {

        // Method PUT(key, values)
        HashMap<Integer, String> hashMap = new HashMap<>();
        hashMap.put(1, "apple");
        hashMap.put(4, "banana");
        hashMap.put(5,"orange");

        // Xuất dữ liệu
        System.out.println("Các phần tử của HashMap khởi tạo vs PUT:");
        output(hashMap);

        // Method PUTALL( nameOtherMap )
        HashMap<Integer, String> hashMapAdd = new HashMap<>();
        hashMapAdd.put(2,"cherry");
        hashMapAdd.put(3,"strawberry");
        hashMap.putAll(hashMapAdd);

        // Xuất dữ liệu
        System.out.println("\nCác phần tử của HashMap mới thêm với PUTALL:");
        output(hashMap);


        // Get element have key = 2
        String printValueByKey = hashMap.get(2);
        System.out.println("\nGiá trị của key 2 trong HashMap là: " + printValueByKey);
//
//        // remove element
//
        // Method Remove(key)
        hashMap.remove(1);
        System.out.println("Các phần tử còn lại sau khi xóa phần tử có key = 1 là:");
        output(hashMap);

        //Method clear()
        hashMap.clear();
        System.out.println("\nCác phần tử sau khi dùng phương thức clear là:");
        output(hashMap);

//
//
//        // update element have key = 2(cherry)
//        hashMap.put(2, "cherry123");
//        System.out.println("HashMap sau khi sửa phần tử có key 2 là:");
//        output(hashMap);


        // convert HashMap to ArrayList
//        ArrayList<String> arrayList = new ArrayList<>();
//        for (String value : hashMap.values()) {
//            arrayList.add(value);
//        }
//        System.out.println("\nMảng arraylist là: ");
//        for (String item : arrayList)
//            System.out.print(item + "\t");

        // convert HashMap to TreeMap
//        TreeMap<Integer, String > treeMap1 = new TreeMap<>();
//        treeMap1.putAll(hashMap);
//        System.out.println("\nMảng treemap1 là");
//        for (String item : treeMap1.values())
//            System.out.print(item + "\t");
    }

//    HashMap<KeyType, ValueType> hashMap = new HashMap<>();
}