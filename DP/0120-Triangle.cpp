/*
題目：
https://leetcode.com/problems/triangle/

解說：
dp(i, j)的定義為,當move到(row, col) = (i, j)時, 其最小值為多少
若要move到(i, j)上個位置會是(i-1, j)、(i-1, j-1)

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1,INT_MAX/2));
        dp[1][1] = triangle[0][0];
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=triangle[i-1].size(); j++)
            {
                dp[i][j] = min(dp[i-1][j] + triangle[i-1][j-1], dp[i-1][j-1] + triangle[i-1][j-1]);
            }
        }
        
        int min_sum = INT_MAX;
        for(int sum : dp[n]) min_sum = min(min_sum, sum);
        return min_sum ;
    }
};
