class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0)
            return 0;
        int end=s.length()-1;
        while(s[end]==' '&&end>=0){
            end--;
        }
        if(end<0)
            return 0;
        int start=end-1;
        while(start>=0&&s[start]!=' ')
            start--;
        if(start<0)
            return end+1;
        else if(start==0){
            if(s[start]==' ')
                return end;
            else
                return end+1;
        }
        else
            return end-start;
    }
};