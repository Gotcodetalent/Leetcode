/*
題目：
https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/

解說：
j的範圍是1~n-2,先線性的在此範圍內得出每個index j所能對應到的最小nums[i] & nums[k],並記錄在一維的vector中
I[j]代表在j的index為j時所能對應到的最小nums[i],同理K[i]為index為 j時所能對應到的最小nums[k]
接著再線性的在j的範圍搜索一次,若滿足nums[i] < nums[j] && nums[k] < nums[j], 則更新sum的value

有使用到的觀念：
Greedy, two pointer
*/

// #include "../code_function.h"
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        const int n = nums.size();
        const int MAX = 51;
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
