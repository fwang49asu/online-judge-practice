struct TrieNode{
    TrieNode *children[26];
    bool isWord;
    TrieNode(): isWord(false){
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};


class WordDictionary {
private:
    TrieNode* root;
public:
    
    WordDictionary(){
        root=new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.length();i++){
            int t=word[i]-'a';
            if(!p->children[t])
                p->children[t]=new TrieNode();
            p=p->children[t];
        }
        p->isWord=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word,root,0);
    }
    
    bool searchWord(string &word, TrieNode *p, int i){
        if(i==word.size())
            return p->isWord;
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(p->children[j])
                    if(searchWord(word,p->children[j],i+1))
                        return true;
            }
            return false;
        }
        else if(p->children[word[i]-'a'])
            return searchWord(word,p->children[word[i]-'a'],i+1);
        else
            return false;
    }
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");