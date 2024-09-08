/*
題目：
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150


解說：
會平移k%n格,所以原本在位置i,最後會落在(i+k)%n的位置
先copy在一個vector,最後assign

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        const int n = nums.size();
        vector<int> copy(n,0);
        for(int i=0; i<n; i++)
        {
            copy[(i+k)%n] = nums[i];
        }
        for(int i =0;i<n; i++)
        {
            nums[i]=copy[i];
        }
        return;
    }
};
