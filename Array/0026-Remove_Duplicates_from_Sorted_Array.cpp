/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
給定一個sorted in non-decreasing order的整數陣列,in-place的移除重複的元素,並返回value k *移除後的陣列之前k個元素要是所有元素的集合*。 

解說：
使用2個pointer -> i,j , i指到陣列第一個元素, j則從第二個元素開始指。
當i指到的元素與j指到的相同時, 則將j指往下一個元素,
若不同時, 則將i指往下一個元素, 並將j所指的元素賦值給i所指的元素 (表示目前探查到的所有元素可以由陣列中的前i+1個元素所表示)


有使用到的觀念：
Array, TwoPointer
*/

// #include "../code_function.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return 1;
        int size = nums.size();
        int i = 0, j = 1;
        while(j < size)
        {
            if(nums[i] == nums[j])
            {
                j++;
            }   
            else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }

        return i+1;
    }
};
