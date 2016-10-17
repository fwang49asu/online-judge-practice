public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder builder = new StringBuilder();
        builder.append(strs.size() + " ");
        for(String str: strs) {
            builder.append(str.length() + " ");
            builder.append(str);
        }
        return builder.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        ArrayList<String> result = new ArrayList<>();
        int i=0;
        for(i=0; i<s.length() && s.charAt(i) != ' '; ++i);
        int n = Integer.parseInt(s.substring(0, i));
        ++i;
        for(; n>0; --n) {
            int low = i;
            for(; i<s.length() && s.charAt(i) != ' '; ++i);
            int length = Integer.parseInt(s.substring(low, i));
            ++i;
            result.add(s.substring(i, i+length));
            i += length;
        }
        return result;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
