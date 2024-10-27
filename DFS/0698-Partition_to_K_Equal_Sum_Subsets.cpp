/*
題目：
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

解說：
概念與0473同,只是會有重複的元素, 當選到重覆的就繼續

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int n;
    
    bool dfs(int target, int sum, vector<int>& nums, vector<bool>& used, int k, int start) {
        if (k == 1) return true;
        if (sum > target) return false;
        if (sum == target) return dfs(target, 0, nums, used, k - 1, 0);
        int last = -1;
        for (int i = start; i < nums.size(); i++) {
            if (used[i]) continue;
            if(nums[i] == last) continue;
            last = nums[i];
            used[i] = true;
            if (dfs(target, sum + nums[i], nums, used, k, i + 1)) return true;
            used[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;

        sort(nums.rbegin(), nums.rend());  // 從大到小排序以進行有效的剪枝
        vector<bool> used(nums.size(), false);
        return dfs(target, 0, nums, used, k, 0);
    }
};
