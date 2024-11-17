/*
題目：
https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        const int n = nums.size();
        long long a = 0, b = 0, c = 0;
        for(int num : nums)
        {
            long long tmp = min({a,b,c}) + max(0, k - num);
            a = b;
            b = c;
            c = tmp; 
        }

        return min({a,b,c});
    }
};
