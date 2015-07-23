class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> ind;
        int i=0;
        int maxArea=0;
        height.push_back(0);
        for(int i=0;i<height.size();i++){
            if(ind.empty()||height[ind.top()]<=height[i]){
                ind.push(i);
            }
            else{
                int tmp=ind.top();
                ind.pop();
                maxArea=max(maxArea,height[tmp]*(ind.empty()?i:i-ind.top()-1));
                i--;
            }
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> height(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    height[i][j]=0;
                }
                else{
                    if(i==0)
                        height[i][j]=1;
                    else
                        height[i][j]=height[i-1][j]+1;
                }
            }
        }
        int maxVal=0;
        for(int i=0;i<matrix.size();i++)
            maxVal=max(maxVal,largestRectangleArea(height[i]));
        return maxVal;
    }
};