/*
題目：
https://leetcode.com/problems/contiguous-array/

解說：
計算前綴和, 遇到 0 減一 , 遇到 1 加一
 遍歷 array 的過程中, 使用 hash map 記錄前綴和, 當前綴和重複出現時, 代表中間有經過一段合法的區段 (中間的 sum 為 0)

有使用到的觀念：
HashMap, Prefix sum
*/

// #include "../code_function.h"
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> prefixSum;
        int sum = 0;
        int max_len = 0;
        prefixSum[0] = -1;

        for(int i=0; i<nums.size(); i++)
        {
            sum += (nums[i] == 1) ? 1 : -1;
            if(prefixSum.count(sum)) max_len = max(max_len, i - prefixSum[sum]);
            else prefixSum[sum] = i;
        }

        return max_len;
    }
};
