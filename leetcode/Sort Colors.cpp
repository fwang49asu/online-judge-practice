class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,blue=nums.size()-1,i=0;
        while(i<=blue){
            if(nums[i]==0){
                swap(nums[red],nums[i]);
                red++;
                i++;
                continue;
            }
            if(nums[i]==2){
                swap(nums[blue],nums[i]);
                blue--;
                continue;
            }
            i++;
        }
    }
};