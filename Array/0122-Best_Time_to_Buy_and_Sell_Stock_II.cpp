/*
題目：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

解說：
rev = max(rev, buy + prices[i]);
buy = max(buy, rev - prices[i]);

max(目前最大獲利,先前持有+今天賣出) -> 得出最大獲利rev
max(先前扣除持有成本的獲利[先前獲利 - 先前買進成本], 當前扣除持有成本的獲利[當前獲利 - 當日買進成本]) -> 得出當前最佳買點,buy為買進後的盈餘,下次計算最大獲利rev時,便會將那天賣出的價錢加入

首先將rev設為0,接著初始化購買後盈餘為"0扣掉第一天的價格"(即0 - prices[0])
接著查看後續每一天的價格是否有比較高
若較高則賣出 -> max(rev, buy + prices[i]) 
若較低則購入 -> max(buy, rev - prices[i]) 並更新購買後的盈餘(rev - prices[i]),於下個高點售出時與售價相加(buy + prices[i]) 

有使用到的觀念：
DP,Greedy (使用前要思考greedy是否可行,在此情境下可以)

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
