/*
題目：
https://leetcode.com/problems/majority-element/description/

解說：


有使用到的觀念：
Array, Hash
*/

// #include "../code_function.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        const int n = nums.size();
        if(n < 2) return nums[0];

        unordered_map<int, int> dp;
        for(int i=0; i<n; i++)
        {
            dp[nums[i]]++;
            if(dp[nums[i]] > n/2) return nums[i];
        }

        return -1;
    }
};
