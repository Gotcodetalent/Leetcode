/*
題目：
https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/description/

解說：
同2903

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        const int n = nums.size();
        int min_index = 0;
        int max_index = 0;
        for(int i=indexDifference; i<n; i++) {
            if(nums[i - indexDifference] < nums[min_index]) min_index = i - indexDifference;
            if(nums[i - indexDifference] > nums[max_index]) max_index = i - indexDifference;
            if(abs(nums[i] - nums[min_index]) >= valueDifference) return {min_index,i};
            if(abs(nums[i] - nums[max_index]) >= valueDifference) return {max_index,i};
        }

        return {-1,-1};
    }
};
