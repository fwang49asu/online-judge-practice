public class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        String[] diffs = new String[strings.length];
        for(int i=0; i<strings.length; ++i) {
            if(strings[i].length() == 0) {
                diffs[i] = null;
                continue;
            }
            diffs[i] = "";
            for(int k=1; k<strings[i].length(); ++k) {
                diffs[i] += (char)((strings[i].charAt(k) - strings[i].charAt(k-1)+26)%26 + 'a');
            }
        }
        HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        for(int i=0; i<strings.length; ++i) {
            if(!map.containsKey(diffs[i])) {
                map.put(diffs[i], new ArrayList<String>());
            }
            map.get(diffs[i]).add(strings[i]);
        }

        ArrayList<List<String>> result = new ArrayList<List<String>>();
        for(ArrayList<String> list: map.values()) {
            result.add(list);
        }
        return result;
    }
}
