class Solution {
public:
    int findKth(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k){
        int size1=nums1.size();
        int size2=nums2.size();
        if(size1-start1>size2-start2){
            return findKth(nums2,start2,nums1,start1,k);
        }
        else if(size1-start1==0){
            return nums2[start2+k-1];
        }
        else if(k==1)
            return min(nums1[start1],nums2[start2]);
        
        int i=min(size1-start1,k/2);
        int j=min(size2-start2,k/2);
        if(nums1[start1+i-1]>nums2[start2+j-1])
            return findKth(nums1, start1, nums2, start2+j, k-j);
        else
            return findKth(nums1, start1+i, nums2, start2, k-i);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=(nums1.size()+nums2.size()+1)/2;
        int r=(nums1.size()+nums2.size()+2)/2;
        return (findKth(nums1, 0, nums2,0,l)+findKth(nums1, 0, nums2,0,r))/2.0;
    }
};