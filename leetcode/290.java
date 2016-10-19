public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if(words.length != pattern.length()) {
            return false;
        }
        HashMap<Character, String> forwardMap = new HashMap<>();
        HashMap<String, Character> backMap = new HashMap<>();
        for(int i=0; i<words.length; ++i) {
            String word = words[i];
            char c = pattern.charAt(i);
            if(forwardMap.containsKey(c)) {
                if(!forwardMap.get(c).equals(word)) {
                    return false;
                }
            } else {
                forwardMap.put(c, word);
            }
            if(backMap.containsKey(word)) {
                char a = backMap.get(word);
                if(a != c) {
                    return false;
                }
            } else {
                backMap.put(word, c);
            }
        }
        return true;
    }
}
