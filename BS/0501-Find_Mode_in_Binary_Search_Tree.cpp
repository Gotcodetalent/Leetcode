/*
題目：
https://leetcode.com/problems/find-mode-in-binary-search-tree/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        find(root);
        return modes;
    }
    void find(TreeNode* root)
    {
        if(root->left) find(root->left);
       
        curr_count = curr_val == root->val ? curr_count+1 : 1;
        if(curr_count == max_count) modes.push_back(root->val);
        if(curr_count > max_count)
        {
            max_count = curr_count;
            modes = {root->val};
        }
        curr_val = root->val;
        
        if(root->right) find(root->right);
    }
private:
    int curr_count = 0;
    int max_count = 0;
    int curr_val = 0;
    vector<int> modes;
};
