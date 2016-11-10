public class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int result = 0;
        int n = points.length;
        for(int i=0; i<n; ++i) {
            HashMap<Integer, Integer> map = new HashMap<>();
            for(int k=0; k<n; ++k) {
                if(i == k) {
                    continue;
                }
                int distance = getDistance(points[i], points[k]);
                int next = map.get(distance) == null ? 0 : map.get(distance);
                ++next;
                map.put(distance, next);

            }
            for(int x : map.values()) {
                result += x * (x-1);
            }
        }
        return result;
    }

    private int getDistance(int[] a, int[] b) {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return x * x + y * y;
    }
}
