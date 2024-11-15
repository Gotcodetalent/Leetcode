/*
題目：
https://leetcode.com/problems/count-number-of-ways-to-place-houses/

解說：
上下兩排不互相影響, 因此只要求出單排長度n的合法數後進行相乘即可
對於位置i來說有兩種可能性:
1.有放置 -> i-1不能放,所以合法數與i-2相同
2.沒放置 -> i-1可以放,與i-1的合法數相同

因此dp[i] = dp[i-1] + dp[i-2], 即fabonacci

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countHousePlacements(int n) {
        constexpr int M = 1e9+7;
        vector<long> dp(n+1);
        long prev1 = 1, prev2 = 2;
        for(int i=2; i<=n; i++)
        {
            long curr = (prev1 + prev2) % M;
            prev1 = prev2;
            prev2 = curr;
        }

        return (prev2 * prev2) % M;
    }
};
