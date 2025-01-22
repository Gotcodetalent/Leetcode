/*
題目：
https://leetcode.com/problems/find-the-k-or-of-an-array/

解說：


有使用到的觀念：
bits operation

*/

// #include "../code_function.h"
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> bits(32,0);
        for(int& num : nums)
        {
            for(int i=0; i<32; i++)
            {
                bits[i] += (num >> i) & 1;
            }
        }

        int ans = 0;
        for(int i=0; i<32; i++)
        {
            if(bits[i] >= k) ans += (1 << i);
        }

        return ans;
    }
};
