public class Solution {
    public int shortestDistance(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        ArrayList<int[]> buildings = new ArrayList<>();
        int n = grid.length;
        int m = grid[0].length;
        int buildingCount = 0;
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                if(grid[i][k] == 1) {
                    buildings.add(new int[]{i, k});
                }
            }
        }
        buildingCount = buildings.size();

        int distance[][] = new int[n][m];
        int count[][] = new int[n][m];
        for(int i=0; i<buildingCount; ++i) {
            bfs(distance, count, buildings.get(i), grid);
        }
        int result = Integer.MAX_VALUE;
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                if(grid[i][k] != 0 || count[i][k] != buildingCount) {
                    continue;
                }
                result = Math.min(result, distance[i][k]);
            }
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }

    private void bfs(int[][] distance, int[][] count, int[] center, int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean visited[][] = new boolean[n][m];
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(center);
        int dist = 1;
        int[] offset = {-1, 0, 1, 0, -1};
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i=0; i<size; ++i) {
                int[] cur = q.poll();
                for(int t=0; t<4; ++t) {
                    int y = cur[0] + offset[t];
                    int x = cur[1] + offset[t+1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[y][x] == 0 && !visited[y][x]) {
                        visited[y][x] = true;
                        ++count[y][x];
                        distance[y][x] += dist;
                        q.offer(new int[]{y, x});
                    }
                }
            }
            ++dist;
        }
    }
}
