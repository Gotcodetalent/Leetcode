/*
題目：
https://leetcode.com/problems/generate-parentheses/

解說：
右括號數量不可大於左括號,字串長度不大於2n

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<string> ans;

    void dfs(int n, int l, int r, string tmp) {
        if (r > l || l > n || r > n) return; 
        if (l == n && r == n) { 
            ans.push_back(tmp);
            return;
        }
        dfs(n, l + 1, r, tmp + '(');
        dfs(n, l, r + 1, tmp + ')'); 
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
};
