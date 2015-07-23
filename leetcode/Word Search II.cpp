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

class Solution {
private:
    Trie trie;
public:
    void isFound(vector<vector<char>> &board, vector<vector<bool>> &visited, unordered_set<string> &res, string &word, int i, int j){

        if(i<0||j<0||i>=board.size()||j>=board[0].size()||visited[i][j]||!trie.startsWith(word))
            return;
        visited[i][j]=true;
        word.push_back(board[i][j]);        
        if(trie.search(word)){
            if(res.find(word)==res.end())
                res.insert(word);
        }
        if(trie.startsWith(word)){
            isFound(board,visited,res,word,i+1,j);
            isFound(board,visited,res,word,i,j+1);
            isFound(board,visited,res,word,i-1,j);
            isFound(board,visited,res,word,i,j-1);
        }
        word.pop_back();
        visited[i][j]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        unordered_set<string> tmpres;
        string tmp="";
        if(board.size()==0)
            return res;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<words.size();i++)
            trie.insert(words[i]);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                isFound(board,visited,tmpres,tmp,i,j);
            }
        }
        for(unordered_set<string>::iterator it=tmpres.begin();it!=tmpres.end();it++){
            res.push_back(*it);
        }
        return res;        
    }
};




// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");