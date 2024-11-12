/*
題目：
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

解說：
Sol 1.
從1顆骰子可能產生的點數,逐步算出2顆, 3顆..., n顆骰子可能產生的點數, 並累計出現的次數

Sol 2.
定義 dp[i][t] 是使用 i 個 dices 可以得到和為 t 的組合數
init: dp[0][0] = 1
dp[i][k] = sum(dp[i-1][t-j]) 1 <= j <= k

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution1 {
public:
    int numRollsToTarget(int n, int k, int target) {
        constexpr long M = 1e9+7;
        unordered_map<long,long> number;
        for(int i=1; i<=k; i++) number[i] = 1; 
        for(int i=1; i<n; i++)
        {
            unordered_map<long, long> tmp;
            for(int j=1; j<=k; j++)
            {
                for(const auto& [key, value] : number)
                {
                    tmp[key + j] += value;
                    tmp[key + j] %= M;
                }
            }
            number = move(tmp);
        }

        return number[target];

    }
};

class Solution2 {
    int kMod = 1e9+7;
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<int>dp(target+1, 0);

        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int t = target; t >= 0; t--)
            {
                dp[t] = 0;
                for(int j = 1; j <= k && j <= t; ++j)
                    dp[t] = (dp[t] + dp[t-j])%kMod;
            }
        }

        return dp[target];
    }
};
