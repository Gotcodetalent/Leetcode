/*
題目：
https://leetcode.com/problems/jump-game/

解說：
從頭開始jump的話直覺上會使用到一個current變數來記錄目前最遠可以到達哪個index,並linear scan每個元素。
但需要考慮到多個因素, 例如我們會利用判斷(nums[i] == 0)來剔除 '首個元素為0' && '無法跳躍'的情況, 但是會同時包含不合法(0,2,3)、合法(2,0,0)的例子,使得程式變得複雜。

因此我們換個角度從尾巴出發, 從尾巴開始scan, 使用last變數來記錄目前'離末端最遠'且可以跳躍到陣列末端的index值是多少, 初始值為nums.size() - 1。
若有某個元素, 其index值(i)+jump值(nums[i]) >= last, 代表可以藉由它來跳躍到末端, 則更新last值, 掃描完後若last值等於0的話, 代表可以從頭跳躍到末端。
此方法可以排除jump值為0時需考慮的情況(last不會更新, ex: 假設last == i 且 nums[i-1]為0, 則 i > i - 1, nums[i] >= nums[i-1](0))。

有使用到的觀念：
Array

*/

// #include "../code_function.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int  last = nums.size()-1;
        int  n = nums.size()-1;
        for(int i=n; i>=0; i--)
        {
            if(nums[i]+i >= last) last = i;
        }
        return last == 0;
    }
};
