public class Solution {
    public String frequencySort(String s) {
        class Pair implements Comparable<Pair>{
            char c;
            int count;
            public Pair(char c) {
                this.c = c;
                count = 0;
            }
            @Override
            public int compareTo(Pair t) {
                if(count > t.count) {
                    return -1;
                }
                if(count < t.count) {
                    return 1;
                }
                return 0;
            }
        }
        Pair[] counts = new Pair[128];
        for(int i=0; i<128; ++i) {
            counts[i] = new Pair((char)i);
        }
        for(int i=0; i<s.length(); ++i) {
            char c = s.charAt(i);
            ++counts[c].count;
        }
        Arrays.sort(counts);
        StringBuilder builder = new StringBuilder();
        for(int i=0; i<128 && counts[i].count > 0; ++i) {
            for(int k=0; k<counts[i].count; ++k) {
                builder.append(counts[i].c);
            }
        }
        return builder.toString();
    }
}
