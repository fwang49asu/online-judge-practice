public class Solution {
    private class TrieNode {
        public TrieNode() {
            next = new TrieNode[26];
            word = null;
        }
        public TrieNode[] next;
        public String word;
    }

    private void insert(TrieNode root, String word) {
        int n = word.length();
        TrieNode curNode = root;
        for(int i=0; i<n; ++i) {
            int index = word.charAt(i) - 'a';
            if(curNode.next[index] == null) {
                curNode.next[index] = new TrieNode();
            }
            curNode = curNode.next[index];
        }
        curNode.word = word;
    }

    private class Position {
        public int x;
        public int y;

        public Position() {
            x = 0;
            y = 0;
        }
        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private void dfs(char[][] board, int row, int col, TrieNode root, boolean[][] visited, ArrayList<String> result) {
        if(root == null) {
            return;
        }
        if(root.word != null) {
            result.add(root.word);
            root.word = null;
        }

        int n = board.length;
        int m = board[0].length;
        visited[row][col] = true;
        if(row >= 1 && !visited[row-1][col]) {
            dfs(board, row-1, col, root.next[board[row-1][col]-'a'], visited, result);
        }
        if(row < (n-1) && !visited[row+1][col]) {
            dfs(board, row+1, col, root.next[board[row+1][col]-'a'], visited, result);
        }
        if(col >= 1 && !visited[row][col-1]) {
            dfs(board, row, col-1, root.next[board[row][col-1]-'a'], visited, result);
        }
        if(col < (m-1) && !visited[row][col+1]) {
            dfs(board, row, col+1, root.next[board[row][col+1]-'a'], visited, result);
        }
        visited[row][col] = false;
    }

    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        // build trie tree
        for(String word: words) {
            insert(root, word);
        }
        ArrayList<String> result = new ArrayList<>();
        int n = board.length;
        int m = board[0].length;
        boolean visited[][] = new boolean[n][m];
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                visited[i][k] = false;
            }
        }
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                dfs(board, i, k, root.next[board[i][k] - 'a'], visited, result);
            }
        }
        return result;
    }
}
