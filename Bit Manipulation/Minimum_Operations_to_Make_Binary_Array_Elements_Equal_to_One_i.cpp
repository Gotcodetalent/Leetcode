/*
題目：
https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n-2; ++i)
        {
            if(nums[i] == 0)
            {
                nums[i] = 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                ++ans;
            }
        }

        if(nums[n-1] == 0 || nums[n-2] == 0) return -1;
        else return ans;
    }
};
