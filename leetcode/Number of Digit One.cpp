class Solution {
public:
    int countDigitOne(int n) {
        int res=0;
        int high=n,lowc=1,lown=0;
        while(high>0){
            int curn=high%10;
            high/=10;
            if(curn==1){
                res+=high*lowc;
                res+=lown+1;
            }
            else if(curn==0){
                res+=high*lowc;
            }
            else{
                res+=(high+1)*lowc;
            }
            lown=curn*lowc+lown;
            lowc*=10;
        }
        return res;
    }
};