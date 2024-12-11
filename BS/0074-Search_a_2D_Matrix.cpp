/*
題目：
https://leetcode.com/problems/search-a-2d-matrix/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int total = m * n;
        int left = 0, right = total - 1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target)
            {
                left = mid + 1; 
            } 
            else right = mid - 1;
        }

        return false;
    }
};
