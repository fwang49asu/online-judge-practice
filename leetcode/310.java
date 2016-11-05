public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        ArrayList<Integer> result = new ArrayList<>();
        if(n == 0) {
            return result;
        }
        ArrayList<Integer>[] adjMap = new ArrayList[n];
        for(int i=0; i<n; ++i) {
            adjMap[i] = new ArrayList<>();
        }
        for(int[] edge: edges) {
            adjMap[edge[0]].add(edge[1]);
            adjMap[edge[1]].add(edge[0]);
        }
        // construct the longest path
        // find the first end
        // find the second and the whole path
        int prev[] = new int[n];
        int dist[] = new int[n];
        bfs(0, prev, dist, adjMap);
        int start = 0;
        for(int i=0; i<n; ++i) {
            if(dist[i] > dist[start]) {
                start = i;
            }
        }
        bfs(start, prev, dist, adjMap);
        int end = 0;
        for(int i=0; i<n; ++i) {
            if(dist[i] > dist[end]) {
                end = i;
            }
        }
        ArrayList<Integer> path = new ArrayList<>();
        for(int i = end; i != -1; i = prev[i]) {
            path.add(i);
        }
        result.add(path.get(path.size() / 2));
        if((path.size() & 1) == 0) {
            result.add(path.get(path.size() / 2 - 1));
        }
        return result;
    }

    void bfs(int start, int[] prev, int[] dist, ArrayList<Integer>[] adjMap) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.offer(start);
        Arrays.fill(dist, -1);
        dist[start] = 0;
        prev[start] = -1;
        while(!q.isEmpty()) {
            int cur = q.poll();
            ArrayList<Integer> neighbors = adjMap[cur];
            for(int x : neighbors) {
                if(dist[x] != -1) {
                    continue;
                }
                prev[x] = cur;
                dist[x] = dist[cur] + 1;
                q.offer(x);
            }
        }
    }
}
