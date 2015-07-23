class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,false);
        for(int i=2;i<n;i++)
            isPrime[i]=true;
        for(int i=2;i*i<n;i++){
            if(!isPrime[i])
                continue;
            for(int j=i*i;j<n;j+=i){
                isPrime[j]=false;
            }
        }
        int res=0;
        for(int i=2;i<n;i++){
            if(isPrime[i])
                res++;
        }
        return res;
    }
};