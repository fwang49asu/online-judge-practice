class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        int cur=0, num=0, t=0, tmax=0;
        while(cur<n){
            if(t>=n-1)
                break;
            while(cur<=t){
                tmax=max(tmax,nums[cur]+cur);
                cur++;
            }
            num++;
            t=tmax;
        }
        return num;
    }
};

//update max range during iterating curent range