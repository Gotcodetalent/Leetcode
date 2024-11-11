/*
題目：
https://leetcode.com/problems/binary-trees-with-factors/

解說：
parent必須為children的product, 因此從最小的node開始逐步算出,以各個node為root時可以產生幾種變化
逐步計算出各個node的情況,最後加總即為解

有使用到的觀念：
DP, Hash table
*/

// #include "../code_function.h"
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        constexpr long kmod = 1000000007;
        const int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;

        for(int i=0; i<n; i++)
        {
            dp[arr[i]] = 1;
            for(int j=0 ; j<i; j++)
            {
                if(arr[i]%arr[j] == 0 && dp.count(arr[i]/arr[j]))
                {
                    dp[arr[i]] += (dp[arr[i]/arr[j]] * dp[arr[j]]) % kmod;
                }
            }
        }

        long ans = 0;
        for(auto tree : dp)
        {
            ans += tree.second;
        }

        return ans%kmod;
    }
};

