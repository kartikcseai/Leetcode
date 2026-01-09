class Solution {
public:
    int replace_with_max(vector<vector<int>>& matrix, int j){
        int max_element=matrix[0][j];
        for(int i=0;i<matrix.size();i++) if(matrix[i][j]>max_element) max_element=matrix[i][j];
        return max_element;
    }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==-1) matrix[i][j]=replace_with_max(matrix,j);
            }
        }
        return matrix;
    }
};