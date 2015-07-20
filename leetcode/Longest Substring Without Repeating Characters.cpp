class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)
            return s.length();
        unordered_set<char> mark;
        int start=0,end=0,maxlen=INT_MIN;
        for(end=0;end<s.length();end++){
            if(mark.find(s[end])==mark.end()){
                mark.insert(s[end]);
            }
            else{
                maxlen=max(maxlen,end-start);
                while(s[start]!=s[end]){
                    mark.erase(s[start]);
                    start++;
                }
                start++;
            }
        }
        return max(maxlen,end-start);
    }
};