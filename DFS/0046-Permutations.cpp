/*
題目：
https://leetcode.com/problems/permutations/description/

解說：
nums[0] ~ nums[n-1]在index為0時,必定皆為不同的排列
因此以這種方式再對後面n-1,n-2,n-3...個數求不同的排列,直到剩下1個數便為一種排列 (即start == n)

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int n; 
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int start){
        if(start == n){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i<n; i++)
        {
            swap(nums[start],nums[i]);
            dfs(nums, start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(nums,0);
        return ans;
    }
};
