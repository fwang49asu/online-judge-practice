class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++)
            m.insert(make_pair(nums[i],false));
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]])
                continue;
            m[nums[i]]=true;
            int tmp=1;
            for(int j=1;m.find(nums[i]+j)!=m.end();j++){
                m[nums[i]+j]=true;
                tmp++;
            }
            for(int j=1;m.find(nums[i]-j)!=m.end();j++){
                m[nums[i]-j]=true;
                tmp++;
            }
            res=max(res,tmp);
        }
        return res;
    }
};