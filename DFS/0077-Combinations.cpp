/*
題目：
https://leetcode.com/problems/combinations/description/

解說：


有使用到的觀念：
DFS
*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int n, int k, int start, vector<int>& vec) {
        if(k == 0)
        {
            ans.push_back(vec);
            return;
        }
        for(int i=start; i<=n; i++)
        {
            vec.push_back(i);
            dfs(n,k-1,i+1,vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        dfs(n,k,1,vec);
        return ans;
    }
};
