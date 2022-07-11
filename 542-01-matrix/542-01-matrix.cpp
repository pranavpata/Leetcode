class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(); int cols = mat[0].size();
        if (rows == 0) return mat;
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX - 1000));
        
        //check left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                }
                else {
                    if (i > 0) 
                        result[i][j] = min(result[i][j], result[i-1][j] + 1);
                    if (j > 0) 
                        result[i][j] = min(result[i][j], result[i][j-1] + 1);
                }
            }
        }
        
        //check bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1) 
                    result[i][j] = min(result[i][j], result[i+1][j] + 1);
                if (j < cols - 1) 
                    result[i][j] = min(result[i][j], result[i][j+1] + 1);
            }
        }
        
        return result;
    }
};