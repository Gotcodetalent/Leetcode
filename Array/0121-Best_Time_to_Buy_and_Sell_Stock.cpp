/*
題目：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

解說：
預設買入最低點為min (預設為最大值), 賣出最高點為max (預設為最小值), 根據每天價格來更新min, max

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
 
        int max = 0;
        int min = 10001;
        for(int i:prices)
        {
            if(i < min) min = i;
            if(i - min > max) max = i - min;
        }

        return max;

    }
};
