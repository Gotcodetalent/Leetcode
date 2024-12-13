/*
題目：
https://leetcode.com/problems/binary-subarrays-with-sum/

解說：
以 HashMap 紀錄當前產生過的 sum, 若有 sum - goal 的存在, 就將 table 中記錄具有 sum - goal 的 subarray 數量加總起來
需要注意必須同時遍歷&紀錄, 先記錄的話計算時可能會重複計算到 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> ump;
        ump[0] = 1;
        int sum = 0;
        int subarray = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(ump.count(sum - goal)){
                subarray += ump[sum - goal];
            }
            ump[sum]++;
        }

        return subarray;
    }
};
