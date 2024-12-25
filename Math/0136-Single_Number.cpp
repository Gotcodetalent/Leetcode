/*
題目：
https://leetcode.com/problems/single-number

解說：
XOR 特性

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) ans^=num;
        return ans;
    }
};
