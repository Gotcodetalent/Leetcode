/*
題目：
https://leetcode.com/problems/diameter-of-binary-tree/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int diameter = 0;

    int dfs(TreeNode* root) {
        int a=0,b=0;
        if(root -> left != NULL) a = dfs(root -> left);
        if(root -> right != NULL) b = dfs(root -> right);       
        diameter = max(a+b,diameter);
        return max(a,b) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root);
        return diameter;
    }
};
