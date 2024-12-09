/*
題目：
https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx = INT_MAX/2;
        for(int i=0; i<nums.size()-k+1; i++)
        {
            mx = min(mx,nums[i+k-1] - nums[i]);
        }

        return mx;
    }
};
