class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> expect(256,0);
        vector<int> appear(256,0);
        if(s.length()==0||s.length()<t.length())
            return "";
        for(int i=0;i<t.length();i++)
            expect[t[i]]++;
        int ss=0,ee=0,curlen=0,start=0,minlen=INT_MAX;
        for(ee=0;ee<s.length();ee++){
            if(expect[s[ee]]>0){
                appear[s[ee]]++;
                if(appear[s[ee]]<=expect[s[ee]])
                    curlen++;
            }
            if(curlen==t.length()){
                while(appear[s[ss]]>expect[s[ss]]||expect[s[ss]]==0){
                    appear[s[ss]]--;
                    ss++;
                }
                if(minlen>ee-ss+1){
                    minlen=ee-ss+1;
                    start=ss;
                }
            }
        }
        if(minlen==INT_MAX)
            return "";
        else
            return s.substr(start,minlen);
    }
};