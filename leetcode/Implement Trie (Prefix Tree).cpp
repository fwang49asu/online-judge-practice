class TrieNode {
public:
    // Initialize your data structure here.
    int val;
    TrieNode* children[26];
    TrieNode() {
        val=0;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++){
            int tmp=word[i]-'a';
            if(!p->children[tmp])
                p->children[tmp]=new TrieNode();
            p=p->children[tmp];
        }
        p->val=1;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++){
            int tmp=word[i]-'a';
            if(p->children[tmp])
                p=p->children[tmp];
            else
                return false;
        }
        if(p->val!=0)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p=root;
        for(int i=0;i<prefix.size();i++){
            int tmp=prefix[i]-'a';
            if(p->children[tmp])
                p=p->children[tmp];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");