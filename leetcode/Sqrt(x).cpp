class Solution {
public:
    int mySqrt(int x) {
        long i=0;
        long j=x/2+1;
        while(i<=j){
            long mid=(i+j)/2;
            if(x==mid*mid)
                return mid;
            else if(x<mid*mid){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};