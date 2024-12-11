/*
題目：
https://leetcode.com/problems/two-sum/

解說：
如果沒有人可以跟自己拼成target, 將自己的值存在hashmap中

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0; i<n; i++)
        {
            if(ump.find(target - nums[i]) == ump.end())
            {
                ump[nums[i]] = i;
            }
            else return {ump[target - nums[i]], i};
        }

        return {-1,-1};
    }
};
