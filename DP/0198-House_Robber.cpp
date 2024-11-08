/*
題目：
https://leetcode.com/problems/house-robber/

解說：


有使用到的觀念：
DP

*/

// #include "../code_function.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=1; i<=n; i++)
        {
            for(int j=2; j<=i; j++)
            {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            }
        }

        return dp[n];
    }
};
