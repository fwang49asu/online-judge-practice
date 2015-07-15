class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> &solution, int start){
        if(start==nums.size()){
            return;
        }
        for(int i=start;i<nums.size();i++){
            solution.push_back(nums[i]);
            res.push_back(solution);
            dfs(nums,res,solution,i+1);
            solution.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> solution;
        res.push_back(solution);
        if(nums.size()==0)
            return res;
        sort(nums.begin(),nums.end());
        dfs(nums,res,solution,0);
        return res;
    }
};