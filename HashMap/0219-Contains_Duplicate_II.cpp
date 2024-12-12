/*
題目：
https://leetcode.com/problems/contains-duplicate-ii

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(int i=0; i<nums.size(); i++)
        {
            if(!ump.count(nums[i])) ump[nums[i]] = i;
            else {
                if(abs(ump[nums[i]] - i) <= k) return true;
                ump[nums[i]] = i;
            }
        }

        return false;
    }
};
