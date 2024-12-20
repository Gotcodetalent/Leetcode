/*
題目：
https://leetcode.com/problems/minimum-size-subarray-sum/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, minlen = INT_MAX;
        while(r < nums.size())
        {
            target -= nums[r];
            while(l <= r && target <= 0)
            {
                minlen = min(minlen, r-l+1);
                target += nums[l];
                ++l;
            }

            ++r;
        }

        return minlen == INT_MAX ? 0 : minlen;
    }
};
