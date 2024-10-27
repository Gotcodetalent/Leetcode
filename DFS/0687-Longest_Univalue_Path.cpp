/*
題目：
https://leetcode.com/problems/longest-univalue-path/

解說：
DFS,同時記錄左右子樹較高者並返回給root,只要val相同就能累加長度,反之則歸0,每回合都對LongestPath進行一次更新

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int LongestPath = 0;

    int dfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        int lcurr = 0, rcurr = 0;
        if(root -> left && (root -> left) -> val == root -> val) lcurr = l + 1;
        if(root -> right && (root -> right) -> val == root -> val) rcurr = r + 1;
        LongestPath = max(LongestPath, lcurr + rcurr);

        return max(lcurr, rcurr);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return LongestPath;
    }
};
