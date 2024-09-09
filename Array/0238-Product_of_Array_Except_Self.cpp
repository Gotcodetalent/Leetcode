/*
題目：
https://leetcode.com/problems/product-of-array-except-self/

解說：
對於陣列nums的各個元素,求出除了自己以外的所有元素乘積
使用兩個陣列rp,lp來記錄各個元素的右邊所有元素乘積、左邊所有元素乘積,lp最左邊與rp最右邊初始值為1
接著將rp[i]*lp[i]得出所有的值,使用三個run n次的for loop,複雜度為O(n)

有使用到的觀念：
DP,Array
*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ret(n,0);
        vector<int> rp(n,0);
        vector<int> lp(n,0);
        lp[0] = rp[n-1] = 1;
        for(int i=1; i<n; i++)
        {
            lp[i] = nums[i-1] * lp[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            rp[i] = nums[i+1] * rp[i+1];
        }
        for(int i=0; i<n; i++)
        {
            ret[i] = lp[i] * rp[i];
        }

        return ret;
    }
};
