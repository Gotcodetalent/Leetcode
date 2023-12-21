/*
題目：
https://leetcode.com/problems/remove-element/description/
與26題類似, 但必須移除值與val相同的數值

解說：
使用idx來指向目前目前的k-value,從0開始,並linear scan目前的array中有那些值不是val, 將其依據idx更新,並更新idx值

有使用到的觀念：
Array, TwoPointer
*/

// #include "../code_function.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return NULL;
        int idx = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[idx] = nums[i];
                idx++;
            }
        }

        return idx;
    }
};
