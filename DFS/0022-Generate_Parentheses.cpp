/*
題目：
https://leetcode.com/problems/generate-parentheses/

解說：
右括弧數量不可大於左括弧,字串長度不大於2n

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<string> ans;

    void dfs(int n, int l, int r, string tmp) {
        if (r > l || l > n || r > n) return; 
        if (l == n && r == n) { // 如果已生成所有括號對
            ans.push_back(tmp);
            return;
        }
        dfs(n, l + 1, r, tmp + '('); // 加入左括號
        dfs(n, l, r + 1, tmp + ')'); // 加入右括號
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
};
