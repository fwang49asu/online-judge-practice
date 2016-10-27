public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        HashSet<String> resultSet = new HashSet<>();
        HashSet<String> cur = new HashSet<>();
        cur.add(s);
        while(resultSet.isEmpty()) {
            HashSet<String> next = new HashSet<>();
            for(String str: cur) {
                if(validate(str)) {
                    resultSet.add(str);
                }
                if(!resultSet.isEmpty()) {
                    continue;
                }
                int n = str.length();
                for(int i=0; i<n; ++i) {
                    if(!isParenthes(str.charAt(i))) {
                        continue;
                    }
                    next.add(str.substring(0, i) + str.substring(i+1, n));
                }
            }
            cur = next;
        }
        ArrayList<String> result = new ArrayList<>();
        result.addAll(resultSet);
        return result;
    }

    private boolean isParenthes(char c) {
        return '(' == c || ')' == c;
    }

    private boolean validate(String s) {
        int n = s.length();
        int stack = 0;
        for(int i=0; i<n; ++i) {
            char c = s.charAt(i);
            if(!isParenthes(c)) {
                continue;
            }
            if('(' == c) {
                ++stack;
            } else {
                if(0 == stack) {
                    return false;
                }
                --stack;
            }
        }
        return 0 == stack;
    }
}
