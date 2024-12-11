/*
題目：
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

解說：
sol 1.尋找target的起始位置,以及比target大的數的起始位置
sol 2.找到target後,左右尋找first && end point

有使用到的觀念：

*/

// #include "../code_function.h"
sol 1.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = findFirstPos(nums, target);
        int lastPos = findFirstPos(nums, target + 1) - 1;
        cout << firstPos << " " << lastPos << endl;
        if(firstPos <= lastPos) return {firstPos, lastPos};
        else return {-1, -1};
    }

    int findFirstPos(vector<int> nums, int target)
    {
        int firstPos = nums.size();
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] >= target)
            {
                firstPos = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return firstPos; 
    }
};

sol 2.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        int left = 0, mid = 0, right = n-1;
        while(left <= right)
        {
            mid = left + (right - left)/2;
            if(nums[mid] < target)
            {
                left = mid +1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else break;
        }
        
        if(left > right) return {-1,-1};
        
        int mid1 = mid, mid2 = mid;
        while(mid1 > 0 && nums[mid1-1] == target) --mid1; 
        while(mid2 < n-1 && nums[mid2+1] == target) ++mid2; 
    
        return {mid1,mid2};
    }
};
