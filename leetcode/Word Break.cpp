class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> flag(s.length()+1,false);
        flag[0]=true;
        for(int i=0;i<s.length();i++){
            if(flag[i]){
                for(int j=i+1;j<s.length()+1;j++){
                    if(wordDict.find(s.substr(i,j-i))!=wordDict.end())
                        flag[j]=true;
                }
            }
        }
        return flag[s.length()];
    }
};