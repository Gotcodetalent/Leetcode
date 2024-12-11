/*
題目：


解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        getOrder(root);
        return min_abs;
    }
    void getOrder(TreeNode* root)
    {
        int l = 0,r = 0;
        if(root->left) {
            getOrder(root->left);
            TreeNode* tmp = root->left;
            while(tmp->right) tmp = tmp->right;
            l = tmp->val; 
        }
        if(root->right) {
            getOrder(root->right);
            TreeNode* tmp = root->right;
            while(tmp->left) tmp = tmp->left;
            r = tmp->val; 
        }

        if(root->left) min_abs = min(min_abs, abs(root->val - l));
        if(root->right) min_abs = min(min_abs, abs(root->val - r));

        return;
    }
    int min_abs = INT_MAX/2;
};
