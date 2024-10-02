/*
題目：
https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/

解說：
找出最小的最大pair sum
直覺為先排序, 然後頭尾湊一對,湊出全部的pair sum並比較後得出

有使用到的觀念：
Greedy,Array
*/

// #include "../code_function.h"
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int maxPairSum = 0;
        for (int i = 0; i < n / 2; ++i) {
            maxPairSum = max(maxPairSum, nums[i] + nums[n - 1 - i]);
        }
        return maxPairSum;
    }
};
