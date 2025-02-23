/*
題目：
https://leetcode.com/problems/coin-change-ii/

解說：
Sol 1. DP規劃概念為: 使用前 j 種 coins 組合出 amount 的方法數
Sol 2. 使用全部的 coins 組合出 amount 的方法數

有使用到的觀念：
DP

*/

// #include "../code_function.h"
Sol 1. O(N^2) space

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int n = coins.size();
        vector<vector<uint64_t>> dp(amount + 1, vector<uint64_t>(n + 1, 0));
        
        for(int j = 0; j <= n; ++j) dp[0][j] = 1; // amount 為 0 元時使用前 j 種 coin 組合的方法數
        
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i][j - 1]; //先包含使用前 j-1 種coin的方法數
                if(i >= coins[j-1]) 
                {
                   dp[i][j] += dp[i - coins[j-1]][j];
                }
            }
        }       

        return dp[amount][n];
    }
};

Sol 2.O(N) space

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int n = coins.size();
        vector<vector<uint64_t>> dp(amount + 1, vector<uint64_t>(n + 1, 0));
        
        for(int j = 0; j <= n; ++j) dp[0][j] = 1; // amount 為 0 元時使用前 j 種 coin 組合的方法數
        
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i][j - 1]; //先包含使用前 j-1 種coin的方法數
                if(i >= coins[j-1]) 
                {
                   dp[i][j] += dp[i - coins[j-1]][j];
                }
            }
        }       

        return dp[amount][n];
    }
};

