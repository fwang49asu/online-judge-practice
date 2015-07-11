class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> st;
        unordered_map<char,char> ts;
        if(s.length()!=t.length())
            return false;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(st.find(s[i])==st.end()&&ts.find(t[i])==ts.end()){
                st[s[i]]=t[i];
                ts[t[i]]=s[i];
            }
            else if(st.find(s[i])!=st.end()&&ts.find(t[i])!=ts.end()){
                if(ts[st[s[i]]]!=s[i])
                    return false;
            }
            else
                return false;
        }
        for(int i=0;i<len;i++)
            s[i]=st[s[i]];
        if(s==t)
            return true;
        return false;
    }
};