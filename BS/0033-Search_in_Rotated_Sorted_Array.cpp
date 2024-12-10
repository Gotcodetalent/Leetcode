/*
題目：
https://leetcode.com/problems/search-in-rotated-sorted-array/description/

解說：
先找到平移量 k, 接著BS, 以位移後的realmid查找target 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int k = 0;
        for(int i=0; i<n-1; ++i)
        {
            if(nums[i] > nums[i+1])
            {
                k = i+1;
                break;
            }
        }
        
        int left = 0, right = n-1;

        while(left <= right)
        {
            int mid = (left + (right - left)/2) % n;
            int realmid = (mid + k)%n;
            if(nums[realmid] < target)
            {
                left = mid + 1;
            }
            else if(nums[realmid] > target)
            {
                right = mid - 1;
            }
            else return realmid;
        }


        return -1;
    }
};
