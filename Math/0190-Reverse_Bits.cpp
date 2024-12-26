/*
題目：
https://leetcode.com/problems/reverse-bits/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(uint32_t i=0; i<32; i++)
        {
            if((n >> i)&1) ans += pow(2,31-i);
        }

        return ans;
    }
};
