public class Solution {
    public boolean sequenceReconstruction(int[] org, int[][] seqs) {
        int n = org.length;
        int map[] = new int[n+1];
        Arrays.fill(map, -1);
        int count[] = new int[n];
        for(int i=0; i<n; ++i) {
            map[org[i]] = i;
        }
        for(int[] seq: seqs) {
            if(seq.length == 0) {
                continue;
            }
            int prev = seq[0];
            if(prev <= 0 || prev > n || map[prev] == -1) {
                return false;
            }
            for(int i=1; i<seq.length; ++i) {
                int cur = seq[i];
                if(cur <= 0 || cur > n || map[cur] == -1) {
                    return false;
                }
                count[map[prev]] = Math.max(count[map[prev]], n - map[cur] + 1);
                prev = cur;
            }
            count[map[prev]] = Math.max(count[map[prev]], 1);
        }
        for(int i=0; i<n; ++i) {
            if(count[i] != n - i) {
                return false;
            }
        }
        return true;
    }
}
