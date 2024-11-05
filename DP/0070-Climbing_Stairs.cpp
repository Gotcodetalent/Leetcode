/*
題目：
https://leetcode.com/problems/climbing-stairs/

解說：
一次爬1 or 2格, 求有幾種方法爬到n格

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i=2; i<n+1 ;i++) dp[i] += dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};
