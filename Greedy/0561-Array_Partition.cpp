/*
題目：
https://leetcode.com/problems/array-partition/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i+=2)
        {
            sum += nums[i];
        }

        return sum;
    }
};
