class TrieNode {
    // Initialize your data structure here.
    public TrieNode() {
        next = new TrieNode[26];
        isLeaf = false;
    }

    TrieNode[] next;
    boolean isLeaf;
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
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

    // Returns if the word is in the trie.
    public boolean search(String word) {
        int n = word.length();
        TrieNode curNode = root;
        for(int i=0; i<n; ++i) {
            int index = word.charAt(i) - 'a';
            if(curNode.next[index] == null) {
                return false;
            }
            curNode = curNode.next[index];
        }
        return curNode.isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        int n = prefix.length();
        TrieNode curNode = root;
        for(int i=0; i<n; ++i) {
            int index = prefix.charAt(i) - 'a';
            if(curNode.next[index] == null) {
                return false;
            }
            curNode = curNode.next[index];
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");
