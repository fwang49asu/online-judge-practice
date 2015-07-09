class Solution {
public:
    static bool sortfunc(int i, int j){
        string ij=to_string(i)+to_string(j),ji=to_string(j)+to_string(i);
        return ij>ji?true:false;
    }
    string largestNumber(vector<int>& nums) {
        string res="";
        sort(nums.begin(),nums.end(),sortfunc);
        if(nums[0]==0)
            return "0";
        for(int i=0;i<nums.size();i++)
            res+=to_string(nums[i]);
        return res;
    }       
};