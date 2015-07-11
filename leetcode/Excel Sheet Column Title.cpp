class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n){
            if(n%26==0){
                res.insert(res.begin(),'Z');
                n=(n-1)/26;
            }
            else{
                res.insert(res.begin(),n%26-1+'A');
                n/=26;
            }
        }
        return res;
    }
};