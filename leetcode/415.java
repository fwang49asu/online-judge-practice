public class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder builder = new StringBuilder();
        int n1 = num1.length();
        int n2 = num2.length();
        int n = Math.min(n1, n2);
        int carry = 0;
        for(int i=0; i<n; ++i) {
            int t = num1.charAt(n1-i-1) - '0' + num2.charAt(n2-i-1) - '0' + carry;
            carry = t / 10;
            t = t % 10;
            builder.append((char)(t + '0'));
        }
        if(n1 > n2) {
            for(int i=n; i<n1; ++i) {
                int t = num1.charAt(n1-i-1) - '0' + carry;
                carry = t / 10;
                t = t % 10;
                builder.append((char)(t + '0'));
            }
        } else {
            for(int i=n; i<n2; ++i) {
                int t = num2.charAt(n2-i-1) - '0' + carry;
                carry = t / 10;
                t = t % 10;
                builder.append((char)(t + '0'));
            }
        }
        if(carry > 0) {
            builder.append((char)(carry + '0'));
        }
        return builder.reverse().toString();
    }
}
