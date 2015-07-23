class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=INT_MIN;
        if(height.size()<2)
            return 0;
        int start=0,end=height.size()-1;
        while(start<end){
            water=max(water,(end-start)*min(height[start],height[end]));
            if(height[start]<=height[end])
                start++;
            else
                end--;
        }
        return water;
    }
};