class Solution {
public:
    unordered_map<string,vector<string>> mp;
    vector<vector<string>> res;
    vector<string> path;
    
    void findDict2(string str, unordered_set<string> &dict, unordered_set<string> &next_lev){
        int sz=str.size();
        string s=str;
        for(int i=0;i<sz;i++){
            s=str;
            for(char j='a';j<='z';j++){
                s[i]=j;
                if(dict.find(s)!=dict.end()){
                    next_lev.insert(s);
                    mp[s].push_back(str);
                }
            }
        }
    }
    
    void output(string &start, string last){
        if(last==start){
            reverse(path.begin(),path.end());
            res.push_back(path);
            reverse(path.begin(),path.end());
        }
        else{
            for(int i=0;i<mp[last].size();i++){
                path.push_back(mp[last][i]);
                output(start,mp[last][i]);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        mp.clear();
        res.clear();
        path.clear();
        
        dict.insert(start);
        dict.insert(end);
        
        unordered_set<string> cur_lev;
        cur_lev.insert(start);
        unordered_set<string> next_lev;
        path.push_back(end);
        
        while(true){
            for(auto it=cur_lev.begin();it!=cur_lev.end();it++)
                dict.erase(*it);
            for(auto it=cur_lev.begin();it!=cur_lev.end();it++)
                findDict2(*it,dict,next_lev);
            
            if(next_lev.empty())
                return res;
            
            if(next_lev.find(end)!=dict.end()){
                output(start,end);
                return res;
            }
            
            swap(cur_lev,next_lev);
            next_lev.clear();
        }
        return res;
        
        
        
    }
};