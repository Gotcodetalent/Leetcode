/*
題目：
https://leetcode.com/problems/maximal-square/

解說：
d[i][j] 代表matrix[i][j]能夠組成的最大方塊面積

2*2 方塊面積可以由四個1*1 重疊出來
3*3 可以由四個 2*2方塊重疊出來
… 

左上、左、上 各代表這三個位置能組成的最大方塊面積，這三個加上d[i][j] 能組成的最大方塊面積，取決於重疊區域的大小，因此取min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        int maxEdge = 0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) +  1;
                }

                maxEdge = max(maxEdge, dp[i][j]);
            }
        }

        return maxEdge * maxEdge;
    }
};
