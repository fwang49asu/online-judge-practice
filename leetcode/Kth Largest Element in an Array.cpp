class Solution {
public:
    int patition(vector<int>& nums, int left, int right){
        int pivot=nums[left];
        int l=left+1;
        int r=right;
        while(l<=r){
            if(nums[l]<pivot&&nums[r]>pivot)
                swap(nums[l++],nums[r++]);
            if(nums[l]>=pivot)
                l++;
            if(nums[r]<=pivot)
                r--;
        }
        swap(nums[left],nums[r]);
        return r;
        
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1;
        while(true){
            int l=patition(nums,left,right);
            if(l==k-1)
                return nums[l];
            if(l>k-1)
                right=l-1;
            else
                left=l+1;
        }
    }
};