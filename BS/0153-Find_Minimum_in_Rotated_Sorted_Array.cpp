/*
題目：
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = n-1;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else right = mid;
        } 

        return nums[left];
    }
};
