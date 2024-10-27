/*
題目：
https://leetcode.com/problems/longest-univalue-path/

解說：


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
