import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> map1 = new HashMap<String, Integer>();
        // count the number of occurence of each word in array words1
        for( String word: words1){
            int count = 1;
            if(map1.containsKey(word)){
                count = map1.get(word) + 1;
            }
            map1.put(word, count);
        }

        Map<String, Integer> map2 = new HashMap<String, Integer>();
        // count the number of occurence of each word in array words2
        for( String word: words2){
            int count = 1;
            if(map2.containsKey(word)){
                count = map2.get(word) + 1;
            }
            map2.put(word, count);
        }

        // keySet1 contains all the word/key appearing in array words1
        Set<String> keySet1 = map1.keySet();
        // keySet2 contains all the word/key appearing in array words2
        Set<String> keySet2 = map2.keySet();

        // this set contains all the common keys of 2 map
        Set<String> set = new HashSet<String>();
        // at first, set contains all keys of map1
        set.addAll(keySet1);
        // then, only retaining keys appearing in map2
        set.retainAll(keySet2);

        // result is the number of strings that appear exactly once in each of the two arrays 
        int result = 0;
        for(String key : set){
            // check whether the word appear only once in both map
            if(map1.get(key) == 1 && map2.get(key) == 1) result++;
        }

        return result;
    }
}

public class Count_Common_Words_With_One_Occurrence{
    public static void main(String[] args) {
        String words1[] = new String[]{"leetcode","is","amazing","as","is"};
        String words2[] = new String[]{"amazing","leetcode","is"};

        System.out.println("Number of common words with one occurence: "+ (new Solution()).countWords(words1, words2));
    }
}