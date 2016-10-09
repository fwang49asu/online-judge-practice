public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(numCourses <= 1) {
            return true;
        }
        ArrayList<HashSet<Integer>> neighbors = new ArrayList<HashSet<Integer>>();
        for(int i=0; i<numCourses; ++i) {
            neighbors.add(new HashSet<>());
        }
        for(int[] edge : prerequisites) {
            if(edge[0] == edge[1]) {
                continue;
            }
            neighbors.get(edge[0]).add(edge[1]);
        }
        HashSet<Integer> visited = new HashSet<>();
        for(int i=0; i<numCourses; ++i) {
            if(visited.contains(i)) {
                continue;
            }
            HashSet<Integer> working = new HashSet<>();
            if(!dfs(neighbors, i, working, visited)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfs(ArrayList<HashSet<Integer>> neighbors, int start, HashSet<Integer> working, HashSet<Integer> visited) {
        if(visited.contains(start)) {
            return true;
        }
        if(working.contains(start)) {
            return false;
        }
        working.add(start);
        for(int x : neighbors.get(start)) {
            if(!dfs(neighbors, x, working, visited)) {
                return false;
            }
        }
        visited.add(start);
        return true;
    }
}
