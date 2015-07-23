class Solution {
public:
    void reverseWords(string &s) {
        if(s.length()==0)
            return;
        string tmp="";
        int start=0;
        while(start<s.length()){
            if(s[start]!=' ')
                tmp+=s[start];
            else{
                if(tmp.length()>0&&tmp[tmp.length()-1]!=' ')
                    tmp+=s[start];
            }
            start++;
        }
        if(tmp[tmp.length()-1]==' ')
            tmp.pop_back();
        s=tmp;
        start=0;
        int end=s.length()-1;
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                end=i-1;
                while(start<=end){
                    swap(s[start],s[end]);
                    start++;
                    end--;
                }
                start=i+1;
            }
        }
        end=s.length()-1;
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};