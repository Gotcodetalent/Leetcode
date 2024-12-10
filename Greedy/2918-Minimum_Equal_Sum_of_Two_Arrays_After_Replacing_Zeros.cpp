/*
題目：
https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for(int num : nums1) 
        {
            if(num == 0) ++zero1;
            else sum1 += num;
        }
        
        for(int num : nums2) 
        {
            if(num == 0) ++zero2;
            else sum2 += num;
        }

        sum1 += zero1;
        sum2 += zero2;

        if(sum1 > sum2)
        {
            if(zero2 == 0) return -1;
            else return sum1;
        }
        else if(sum1 == sum2)
        {
            return sum1;
        }
        else
        {
            if(zero1 == 0) return -1;
            else return sum2;
        }
    }
};
