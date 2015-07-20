class Solution {
public:
    void dfs(string &s, unordered_set<string> &wordDict, vector<bool> &flag, int loc, vector<string> &res, string &line){
        if(loc==s.length()){
            line.resize(line.size()-1);
            res.push_back(line);
            return;
        }
        for(int i=loc;i<s.length();i++){
            string t=s.substr(loc,i-loc+1);
            if(flag[i]&&wordDict.count(t)){
                int clen=line.size();
                int cnum=res.size();
                line+=t;
                line+=" ";
                dfs(s,wordDict,flag,i+1,res,line);
                if(res.size()==cnum)
                    flag[i]=false;
                line.resize(clen);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> flag(s.length(),true);
        vector<string> res;
        string line;
        dfs(s,wordDict,flag,0,res,line);
        return res;
    }
};