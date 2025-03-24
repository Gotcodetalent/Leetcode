/*
題目：
https://leetcode.com/problems/house-robber-iv/description/

解說：
利用 binary search, 從 1 to max_element 找到滿足偷到至少 k 間的 money 之最小值

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(nums, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
private:
    bool check(vector<int>& nums, int k, int money)
    {
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= money)
            {
                ++count;
                ++i;
            }
        }

        return count >= k;
    }
};
