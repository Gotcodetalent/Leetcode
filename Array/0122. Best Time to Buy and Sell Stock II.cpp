/*
題目：


解說：
rev = max(rev, buy + prices[i]);
buy = max(buy, rev - prices[i]);

max(目前最大獲利,先前持有+今天賣出) -> 得出最大獲利rev
max(先前扣除持有成本的獲利[先前獲利 - 先前買進成本], 當前扣除持有成本的獲利[當前獲利 - 當日買進成本]) -> 得出當前最佳買點,buy為買進後的盈餘,下次計算最大獲利rev時,便會將那天賣出的價錢加入

有使用到的觀念：
DP,Greedy

*/

// #include "../code_function.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(n < 2) return 0;

        int rev = 0, buy = -prices[0];
        for (int i=1; i<n; i++)
        {
            rev = max(rev, buy + prices[i]);
            buy = max(buy, rev - prices[i]);
        }

        return rev;
    }
};
