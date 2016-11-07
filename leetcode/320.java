public class Solution {
    public List<String> generateAbbreviations(String word) {
        HashSet<String> resultSet = new HashSet<>();
        List<String> result = new ArrayList<>();
        backtrace(word, "", 0, 0, resultSet);
        result.addAll(resultSet);
        return result;
    }

    void backtrace(String word, String cur, int pos, int count, HashSet<String> set) {
        if(pos == word.length()) {
            if(count > 0) {
                cur += count;
            }
            set.add(cur);
            return;
        }
        backtrace(word, cur, pos+1, count+1, set);
        backtrace(word, cur + (count>0 ? count : "") + word.charAt(pos), pos+1, 0, set);
    }
}
