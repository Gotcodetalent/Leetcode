/*
題目：
https://leetcode.com/problems/merge-sorted-array/

解說：
給予兩個sorted array nums1, nums2, 將兩者合併儲存在nums1中, 且不得另外使用空間。
使用插入排序法將nums2插入到nums1中, 且因為array已排序過, 所以插入一個元素後, 下個插入的元素只需要比較到上次插入的位置。
利用一個front變數來記錄上次插入的位置。

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int front = 0, temp = 0;
        for(int i=0; i<n; i++)
        {
            int cur = nums2[i], j;
            for(j=m+i-1; j>=front && cur < nums1[j]; j--)
            {
                nums1[j+1] = nums1[j];
            }
            nums1[j+1] = cur;
            front = j+1;
        }
    }
};
