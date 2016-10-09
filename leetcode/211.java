public class WordDictionary {
    public WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    public void addWord(String word) {
        int n = word.length();
        TrieNode curNode = root;
        for(int i=0; i<n; ++i) {
            int index = word.charAt(i) - 'a';
            if(curNode.next[index] == null) {
                curNode.next[index] = new TrieNode();
            }
            curNode = curNode.next[index];
        }
        curNode.isLeaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        ArrayList<TrieNode> curList = new ArrayList<>();
        curList.add(root);
        int n = word.length();
        for(int i=0; i<n && !curList.isEmpty(); ++i) {
            char c = word.charAt(i);
            ArrayList<TrieNode> nextList = new ArrayList<>();
            for(TrieNode node : curList) {
                if(c == '.') {
                    for(TrieNode x: node.next) {
                        if(x != null) {
                            nextList.add(x);
                        }
                    }
                } else {
                    int index = c - 'a';
                    if(node.next[index] != null) {
                        nextList.add(node.next[index]);
                    }
                }
            }
            curList = nextList;
        }
        for(TrieNode node: curList) {
            if(node.isLeaf) {
                return true;
            }
        }
        return false;
    }

    private class TrieNode {
        public TrieNode[] next;
        public boolean isLeaf;

        public TrieNode() {
           next = new TrieNode[26];
           isLeaf = false;
        }
    }

    TrieNode root;
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
