/*
題目：
https://leetcode.com/problems/knight-dialer/description/

解說：
長度為n的號碼可以分為結尾為0,1,2...,8,9等十種
因此可以DP逐個長度從1,2,...,n-1,n累加到達每個號碼的方法數

dp[N][1] = dp[N-1][6]  + dp[N-1][8]
dp[N][2]
...
dp[N][0]

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int knightDialer(int n) {
        constexpr long M = 1e9+7;
        vector<vector<int>> number = {{4,6},{6,8},{7,9},{4,8},{3,9},{},{1,7},{2,6},{1,3},{2,4}};
        vector<int> dp(10,1);        
        for(int i=1; i<n; i++)
        {
            auto dp_old = dp;
            dp[0] = dp_old[4] + dp_old[6];
            dp[1] = dp_old[6] + dp_old[8];
            dp[2] = dp_old[7] + dp_old[9];
            dp[3] = dp_old[4] + dp_old[8];
            dp[4] = (dp_old[3] + dp_old[9])%M + dp_old[0]; 
            dp[5] = 0;
            dp[6] = (dp_old[1] + dp_old[7])%M + dp_old[0];
            dp[7] = dp_old[2] + dp_old[6]%M;
            dp[8] = dp_old[1] + dp_old[3];
            dp[9] = dp_old[2] + dp_old[4];

            for(int k=0; k<10; k++)
            {
                dp[k] %= M;
            }
        }

        long ans = 0;
        for(int i=0; i<10; i++)
        {
            ans += dp[i];
            ans %= M;
        }

        return ans;
    }
};
