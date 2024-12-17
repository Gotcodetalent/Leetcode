/*
題目：
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

解說：
element 最大值小於等於 right 的 subarray 集合, 包含了 element 最大值小於 left 的集合
因此先算出 (bound <= right) 的情況有幾種, 再扣除 (bound < left) 的情況
剩下的情況就是 left <= bound <= right

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int curr = 0, rsub = 0, lsub = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= right)
            {
                ++curr;
                rsub += curr;
            }
            else curr = 0;
        }

        curr = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < left)
            {
                ++curr;
                lsub += curr;
            }
            else curr = 0;
        }

        return rsub - lsub;
    }
};
