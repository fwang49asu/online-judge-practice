class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size()==0)
            return 1;
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> matrix(m,vector<int>(n));
        matrix[m-1][n-1]=dungeon[m-1][n-1]>=0?1:-dungeon[m-1][n-1]+1;
        for(int i=n-2;i>=0;i--)
            matrix[m-1][i]=max(matrix[m-1][i+1]-dungeon[m-1][i],1);
        for(int i=m-2;i>=0;i--)
            matrix[i][n-1]=max(matrix[i+1][n-1]-dungeon[i][n-1],1);
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                matrix[i][j]=max(min(matrix[i+1][j],matrix[i][j+1])-dungeon[i][j],1);
            }
        }
        return matrix[0][0];
    }
};