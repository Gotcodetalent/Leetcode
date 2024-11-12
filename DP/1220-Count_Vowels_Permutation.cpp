/*
題目：
https://leetcode.com/problems/count-vowels-permutation/

解說：
概念與0935同

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countVowelPermutation(int n) {
        constexpr long M = 1e9+7;
        vector<int> dp(5,1);
        for(int i=1; i<n; i++)
        {
            auto dp_old = dp;
            dp[0] = dp_old[1];
            dp[1] = dp_old[0] + dp_old[2];
            dp[2] = (dp_old[0] + dp_old[1])%M + (dp_old[3] + dp_old[4])%M;
            dp[3] = dp_old[2] + dp_old[4];
            dp[4] = dp_old[0];
            for(int k=0; k<5; k++) dp[k] %= M;
        } 
        
        long ans = 0;
        for(int i=0; i<5;i++)
        {
            ans += dp[i];
            ans %= M;
        }

        return ans;
    }
};
