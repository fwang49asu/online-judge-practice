public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList<Integer> resultList = new ArrayList<>();
        HashSet<Integer> remainingSet = new HashSet<>();
        ArrayList<HashSet<Integer>> parents = new ArrayList<HashSet<Integer>>();
        HashSet<Integer> noHeadSet = new HashSet<>();
        for(int i=0; i<numCourses; ++i) {
            noHeadSet.add(i);
            remainingSet.add(i);
            parents.add(new HashSet<Integer>());
        }
        for(int[] edge: prerequisites) {
            noHeadSet.remove(edge[0]);
            parents.get(edge[0]).add(edge[1]);
        }
        if(noHeadSet.isEmpty()) {
            return new int[0];
        }
        while(!noHeadSet.isEmpty()) {
            Integer[] array = noHeadSet.toArray(new Integer[0]);
            for(Integer root: array) {
                resultList.add(root);
            }
            noHeadSet.clear();
            for(int root : array) {
                remainingSet.remove(root);
            }
            for(int child: remainingSet) {
                for(int root: array) {
                    parents.get(child).remove(root);
                }
                if(parents.get(child).isEmpty()) {
                    noHeadSet.add(child);
                }
            }
        }
        if(!remainingSet.isEmpty()) {
            return new int[0];
        }

        int[] result = new int[numCourses];
        for(int i=0; i<numCourses; ++i) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}
