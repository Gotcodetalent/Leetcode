/*
題目：
https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int current_sum_max = 0, current_sum_min = 0;
        int max_sum = 0, min_sum = 0;

        for(int& num : nums)
        {
            current_sum_max += num;
            max_sum = max(max_sum , current_sum_max);
            if(current_sum_max < 0) current_sum_max = 0;

            current_sum_min += num;
            min_sum = min(min_sum , current_sum_min);
            if(current_sum_min > 0) current_sum_min = 0;

        }
        return max(max_sum, abs(min_sum));
    }
};
