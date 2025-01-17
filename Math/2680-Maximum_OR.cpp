/*
題目：
https://leetcode.com/problems/maximum-or/description/

解說：
題目敘述我們可以對nums中的任意元素左移1個bit, 操作總次數至多k次 (*但題意似乎是指"必須"操作k次)
因此我們只要先記錄出每個數的 "prefix OR sum" 以及 "suffix OR sum" 
再逐個數的 shift k 個 bit 後, 與其 prefix、suffix OR sum 進行 OR 運算, 並記錄最大值即可

*假設有兩個數值 (a, b) 可以操作 k 次 shift, 但兩者操作 k 次後皆會為 0, 則結果並不一定會是maximum。
=> 這樣 maximum 會是 max(a,b), 忽略了 a | b 的可能性, 因此依原本題意直接 shift k 次求最大值的作法並不正確

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> prefix(n,0), suffix(n,0);
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] | nums[i-1];
        for(int i=n-2; i>=0; i--) suffix[i] = suffix[i+1] | nums[i+1];

        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            long long tmp = prefix[i] | suffix[i] | ((long long)nums[i] << k);
            ans = max(ans,tmp);
        }

        return ans;
    }
};
