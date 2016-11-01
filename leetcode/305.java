public class Solution {
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        List<Integer> result = new ArrayList<>();
        UnionFind uf = new UnionFind(m*n);
        for(int[] position : positions) {
            int hash = hashCode(position[1], position[0], m, n);
            int neighbors[] = {
                hashCode(position[1] - 1, position[0], m, n),
                hashCode(position[1] + 1, position[0], m, n),
                hashCode(position[1], position[0]-1, m, n),
                hashCode(position[1], position[0]+1, m, n)
            };

            uf.add(hash);
            for(int nei: neighbors) {
                if(uf.has(nei)) {
                    uf.merge(nei, hash);
                }
            }
            result.add(uf.size());
        }
        return result;
    }

    private class UnionFind {
        private int parent[];
        private int curSize;
        public UnionFind(int n) {
            parent = new int[n];
            Arrays.fill(parent, -1);
            curSize = 0;
        }
        public int size() {
            return curSize;
        }
        public void add(int x) {
            if(parent[x] != -1) {
                return;
            }
            parent[x] = x;
            ++curSize;
        }
        public int find(int x) {
            int p = x;
            while(p != parent[p]) {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }
        public void merge(int x, int y) {
            int px = find(x);
            int py = find(y);
            if(px == py) {
                return;
            }
            parent[px] = py;
            --curSize;
        }
        public boolean has(int x) {
            return x >= 0 && x < parent.length && parent[x] != -1;
        }
    }

    private int hashCode(int x, int y, int rows, int cols) {
        if(x < 0 || y < 0 || x >= cols || y >= rows) {
            return -1;
        }
        return y * cols + x;
    }
}
