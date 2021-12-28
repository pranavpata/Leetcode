class Solution {
public:
    //binary search to find row, then column
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int top = 0, bottom = m - 1;
        while(top <= bottom) {
            int m = top + ((bottom - top) >> 1);
            if(matrix[m][0] > target)
                bottom = m - 1;
            else
                top = m + 1;
        }// b
        int left = 0, right = n - 1;
        while(left <= right) {
            int m = left + ((right - left) >> 1);
            if(matrix[bottom][m] == target)
                return true;
            else if(matrix[bottom][m] > target)
                right = m - 1;
            else
                left = m + 1;
        }
        return false;
    }
};