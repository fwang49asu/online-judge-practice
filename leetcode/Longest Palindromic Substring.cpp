class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        if(s.length()<=1)
            return s;
        for(int i=0;i<s.length();i++){
            int start=i,end=i;
            while(start>=0&&end<s.length()&&s[start]==s[end]){
                start--;
                end++;
            }
            string tmp=s.substr(start+1,end-start-1);
            if(tmp.length()>res.length())
                res=tmp;
            start=i;
            end=i+1;
            while(start>=0&&end<s.length()&&s[start]==s[end]){
                start--;
                end++;
            }
            tmp=s.substr(start+1,end-start-1);
            if(tmp.length()>res.length())
                res=tmp;            
        }
        return res;
    }
};