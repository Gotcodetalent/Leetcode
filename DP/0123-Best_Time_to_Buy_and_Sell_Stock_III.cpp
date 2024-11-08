/*
題目：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

解說：
找出第1~i天、第i+1~n天的最大收益總和
從左到右、從右到左各遍歷一次,可以得到所有需要的組合
接著遍歷所有組合(0,n),(1,n-1),(2,n-2)...(n-2,2),(n-1,1),(n,0) 找出最大值

有使用到的觀念：
DP

*/

// #include "../code_function.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<int> dp1(n,0), dp2(n,0);
        
        int minPrice = prices[0];
        for(int i=1; i<n; i++)
        {
            minPrice = min(minPrice, prices[i]); //最低買入price
            dp1[i] = max(dp1[i-1], prices[i] - minPrice);
        }

        int maxPrice = prices[n-1];
        for(int j=n-2; j>=0; j--)
        {
            maxPrice = max(maxPrice, prices[j]); //最高賣出price
            dp2[j] = max(dp2[j+1], maxPrice - prices[j]);
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans = max(ans,dp1[i] + dp2[i]);
        }

        return ans;
    }
};
