/*
題目：
https://leetcode.com/problems/contains-duplicate-iii

解說：
使用 multiset 來保留重複元素，並且資料會由小到大排序
確保 window 內的元素最多只包含距離當前索引 j 在 indexDiff 範圍內的元素。
透過 ms.erase(ms.lower_bound(nums[j - indexDiff - 1])) 在每回合將超過範圍的元素刪除
ms.lower_bound(nums[j] - valueDiff) 查找第一個大於等於 nums[j] - valueDiff 的元素位置。

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        multiset<long>ms;

        for(int j = 0; j < nums.size(); j++)
        {
            // 如果 j > indexDiff 代表超過 indexDiff 需要刪除前面的
            if(j>indexDiff) ms.erase(ms.lower_bound(nums[j-indexDiff-1])); 

            // nums[j]- valueDiff <= nums[i] <= nums[j] + valueDiff
            auto pos = ms.lower_bound((long)nums[j]-(long)valueDiff);

            if(pos != ms.end() && *pos-nums[j] <= valueDiff) return true;

            ms.insert(nums[j]);
        }

        return false; 
    }
};
