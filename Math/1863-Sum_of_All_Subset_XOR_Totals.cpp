/*
題目：
https://leetcode.com/problems/sum-of-all-subset-xor-totals/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int ans;
    int subsetXORSum(vector<int>& nums) {
        ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            recursive(nums,i,0);
        }

        return ans;
    }

    void recursive(vector<int>& nums, int start, int val)
    {
        if(start >= nums.size()) return;
        val ^= nums[start];
        ans += val;
        for(int i=start+1; i<nums.size(); i++)
        {
            recursive(nums, i, val);
        }
    }
};
