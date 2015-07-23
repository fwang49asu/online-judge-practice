class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        int row0=1,col0=1,row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                col0=0;
                break;
            }
        }
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                row0=0;
                break;
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[0][j]==0||matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }
        if(row0==0){
            for(int i=0;i<col;i++)
                matrix[0][i]=0;
        }
        if(col0==0){
            for(int i=0;i<row;i++)
                matrix[i][0]=0;
        }
    }
};