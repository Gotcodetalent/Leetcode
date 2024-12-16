/*
題目：
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

解說：
遇到 frequency 大於 k 的代表無法再往前了

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int maxlen = 0;
        int i = 0;
        for(int j=0; j<nums.size(); j++)
        {
            ++ump[nums[j]];
            while(ump[nums[j]] > k)
            {
                --ump[nums[i]];
                ++i;
            }
            maxlen = max(maxlen, j-i+1);
        }

        return maxlen;
    }
};
