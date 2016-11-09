public class Solution {
    public int lengthLongestPath(String input) {
        int result = 0;
        Stack<Integer> stack = new Stack<Integer>();
        int n = input.length();
        boolean isFile = false;
        int curCount = 0;
        int tab = 0;
        for(int i=0; i<=n; ++i) {
            char c = i == n ? '\n' : input.charAt(i);
            if(c == '\t') {
                ++tab;
                continue;
            }
            if(c == '\n') {
                // cleanup
                while(stack.size() > tab) {
                    stack.pop();
                }
                assert(stack.size() == tab);
                int curSum = curCount + (stack.isEmpty() ? 0 : stack.peek());
                if(isFile) {
                    if(curSum > result) {
                        result = curSum;
                    }
                } else {
                    stack.push(curSum + 1);
                }
                curCount = 0;
                tab = 0;
                isFile = false;
                continue;
            }
            if(c == '.') {
                isFile = true;
            }
            ++curCount;
        }
        return result;
    }
}
