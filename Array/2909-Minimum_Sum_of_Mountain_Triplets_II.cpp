/*
題目：
https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/

解說：
同2908,但MAX不同

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        const int n = nums.size();
        const int MAX = 100000000;
        vector<int> I(n, MAX);
        vector<int> K(n, MAX);
        int sum = INT_MAX;
        for(int j=1; j<n-1; j++)
        {
            I[j] = min(I[j-1], nums[j-1]);
            K[n-j-1] = min(K[n-j], nums[n-j]);
        }
        for(int j=1; j<n-1; j++)
        {
            if(I[j] < nums[j] && K[j] < nums[j]) sum = min(sum, I[j] + K[j] + nums[j]);
        }

        if(sum == INT_MAX) return -1;
        else return sum; 
    }
};
