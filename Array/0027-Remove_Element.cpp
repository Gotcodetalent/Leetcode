/*
題目：
https://leetcode.com/problems/remove-element/description/
與26題類似, 但必須移除值與val相同的數值

測試用程式:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}

解說：
此解法沒有特別求出k值, 而是更新nums陣列。
使用一個用來更新陣列(nums)內元素的指標(idx)來指向陣列起始位置,並從陣列的頭開始linear scan, 若指標指向的值不等於val, 則將該值放在該指標所指的位置
指標所指之處即為目前所更新到的位置,例如: idx等於3的話,代表已經更新3個元素(idx=0~2),下一個更新位置為idx=3。

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
