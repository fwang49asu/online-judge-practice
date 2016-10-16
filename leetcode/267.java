public class Solution {
    public List<String> generatePalindromes(String s) {
        int n = s.length();
        int half = n >> 1;
        HashMap<Character, Integer> countMap = new HashMap<>();
        for(int i=0; i<n; ++i) {
            char c = s.charAt(i);
            if(countMap.containsKey(c)) {
                countMap.put(c, countMap.get(c) + 1);
            } else {
                countMap.put(c, 1);
            }
        }
        boolean odd = false;
        char center = '0';
        for(HashMap.Entry<Character, Integer> entry: countMap.entrySet()) {
            int count = entry.getValue();
            if((count & 1) == 1) {
                if(odd) {
                    return new ArrayList<String>();
                }
                odd = true;
                center = entry.getKey();
            }
        }
        for(char c: countMap.keySet()) {
            int count = countMap.get(c);
            countMap.put(c, count >> 1);
        }
        char[] base = new char[n];
        if(odd) {
            base[half] = center;
        }
        ArrayList<String> result = new ArrayList<>();
        dfs(countMap, base, half - 1, n, result);
        return result;
    }

    private void dfs(HashMap<Character, Integer> countMap, char[] base, int index, int n, ArrayList<String> result) {
        if(index < 0) {
            result.add(new String(base));
            return;
        }
        for(char c: countMap.keySet()) {
            int count = countMap.get(c);
            if(count == 0) {
                continue;
            }
            countMap.put(c, count-1);
            base[index] = base[n - 1 - index] = c;
            dfs(countMap, base, index - 1, n, result);
            countMap.put(c, count);
        }
    }
}
