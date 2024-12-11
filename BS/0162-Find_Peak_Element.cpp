/*
題目：
https://leetcode.com/problems/find-peak-element/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return FindPeak(nums, 0, nums.size() -1);
    }
    int FindPeak(vector<int> nums, int left, int right){
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            bool leftSmaller = (mid == 0 || nums[mid] > nums[mid-1]);
            bool rightSmaller = (mid == nums.size()-1 || nums[mid] > nums[mid+1]);

            if(leftSmaller && rightSmaller) return mid;

            if(nums[mid] < nums[mid+1])
            {
                left = mid+1;
            }
            else{
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
