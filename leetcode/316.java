public class Solution {
    public String removeDuplicateLetters(String s) {
        char data[] = s.toCharArray();
        char buffer[] = new char[data.length];
        int count[] = new int[26];
        boolean used[] = new boolean[26];
        int index = 0;
        for(char c: data) {
            ++count[c - 'a'];
        }
        for(char c: data) {
            int pos = c - 'a';
            --count[pos];
            if(used[pos]) {
                continue;
            }
            while(index > 0 && buffer[index - 1] > c && count[buffer[index - 1] - 'a'] > 0) {
                used[buffer[index - 1] - 'a'] = false;
                --index;
            }
            used[pos] = true;
            buffer[index] = c;
            ++index;
        }
        StringBuilder builder = new StringBuilder();
        for(int i=0; i<index; ++i) {
            builder.append(buffer[i]);
        }
        return builder.toString();
    }
}
