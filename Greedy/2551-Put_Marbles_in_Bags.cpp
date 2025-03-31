/*
題目：
https://leetcode.com/problems/put-marbles-in-bags/description/

解說：
有 k 個背包, 每個背包都必須裝至少 1 個大理石, 假設放了第 i to j 個大理石到某個包包, 其 cost 為 weights[i] + weights[j]
所以可以理解成 |w[0]---w[i]|w[i+1]---w[j]|w[j+1]---w[n-1]|
如果將w[0], w[n-1]單獨拉開來看, 可以發現圖變成這樣 w[0]---|w[i],w[i+1]|---|w[j],w[j+1]|---w[n-1]
也就是說我們可以將問題視為選取 k-1 個隔間, 而 n 個數總共可以產生 n-1 個隔間
因此我們只要找出所有個隔間的和, 並 sorting後, 選取前 k 大/小的值, 便可以找到最大值以及最小值


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        if (k == 1) return 0;
        
        vector<long long> pairSum;
        const int n = weights.size();
        for(int i = 0; i < n-1; ++i)
        {
            pairSum.push_back(weights[i] + weights[i+1]);
        }

        const int m = pairSum.size();
        sort(pairSum.begin(), pairSum.end());
        long long mn = 0, mx = 0;
        for(int i = 0; i < k-1; ++i)
        {
            mn += pairSum[i];
            mx += pairSum[m-i-1];
        }

        return mx - mn;
    }
};
