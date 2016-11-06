public class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        int[][] result = new int[A.length][B[0].length];
        ArrayList<Tuple> listA = new ArrayList<>();
        ArrayList<Tuple> listB = new ArrayList<>();
        for(int i=0; i<A.length; ++i) {
            for(int k=0; k<A[i].length; ++k) {
                if(A[i][k] != 0) {
                    listA.add(new Tuple(k, i, A[i][k]));
                }
            }
        }
        int indexB[] = new int[B.length];
        for(int i=0; i<B.length; ++i) {
            indexB[i] = listB.size();
            for(int k=0; k<B[i].length; ++k) {
                if(B[i][k] != 0) {
                    listB.add(new Tuple(k, i, B[i][k]));
                }
            }
        }
        for(Tuple t: listA) {
            int x = t.x;
            for(int i=indexB[x]; i<listB.size() && listB.get(i).y == x; ++i) {
                result[t.y][listB.get(i).x] += t.value * listB.get(i).value;
            }
        }
        return result;
    }
    private class Tuple {
        public int x;
        public int y;
        public int value;

        public Tuple(int x, int y, int value) {
            this.x = x;
            this.y = y;
            this.value = value;
        }
    }
}
