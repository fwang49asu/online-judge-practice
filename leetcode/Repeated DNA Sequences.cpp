class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string window="";
        vector<string> res;
        if(s.length()<10)
            return res;
        hash<string> hfunc;
        unordered_map<int,int> table;
        for(int i=0;i<=s.length()-10;i++){
            window=s.substr(i,10);
            int tmp=hfunc(window);
            if(table.find(tmp)==table.end())
                table[tmp]=1;
            else{ 
                if(table[tmp]==1)
                    res.push_back(window);
                table[tmp]++;
            }
        }
        return res;
    }
};