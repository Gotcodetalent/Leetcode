/*
題目：
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
sol 1.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        findOrder(root, order,k);
        return order[k-1];
    }

    void findOrder(TreeNode* root, vector<int>& order, int k)
    {
        if(root->left) findOrder(root->left, order, k);
        order.push_back(root->val);
        if(root->right) findOrder(root->right, order, k);
    }
};

sol 2.
class Solution {
public:
    int order = 0;
    int kthSmallest(TreeNode* root, int k) {
        return findKth(root,k);
    }

    int findKth(TreeNode* root, int k)
    {
        int ret = INT_MAX/2;
        if(root->left) ret = min(ret, findKth(root->left, k));
                
        ++order;
        if(order == k) ret = root->val;
        
        if(root->right) ret = min(ret, findKth(root->right, k));

        return ret;
    }
};
