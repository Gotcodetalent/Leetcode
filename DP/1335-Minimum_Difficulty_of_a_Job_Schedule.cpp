/*
題目：
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

解說：
dp[i][j] 表示將前 i 個工作分配到 j 天內的最小難度和。
同時確保2個條件:
1. 工作數量不小於天數 (保證每天至少有一個工作分配
2. 往前遍歷找min sum時, 最多遍歷到當前天數, 避免產生出使用到的dp[i-1][j-1]會是不合法的情況 (ex: dp[2][3])

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        const int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1, vector<int>(d+1,INT_MAX/2));
        jobDifficulty.insert(jobDifficulty.begin(),0);
        dp[0][0] = 0;

        for(int i=1; i<=n ;i++)
        {
            for(int j=1; j<=min(d,i); j++)
            {
                int mx = jobDifficulty[i];
                for(int k=i; k>=j; k--) // 確保k天內有k個工作可以做
                {
                    mx = max(mx, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[k-1][j-1] + mx);
                }
            }
        }

        if(dp[n][d] >= INT_MAX/2) return -1;
        return dp[n][d];

    }
};
