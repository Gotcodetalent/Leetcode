/*
題目：
https://leetcode.com/problems/minimum-path-sum/

解說：
DP求出最小路徑總和

有使用到的觀念：
DP

*/

// #include "../code_function.h"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int tmp1 = INT_MAX, tmp2 = INT_MAX;
                if(i > 0) tmp1 = dp[i-1][j] + grid[i][j];
                if(j > 0) tmp2 = dp[i][j-1] + grid[i][j];
                if(i > 0 || j > 0) dp[i][j] += min(tmp1,tmp2);
            }
        }

        return dp[m-1][n-1];
    }
};
