/*
題目：
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

解說：
0102再多一個bool變數決定是否要reverse

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool zigzag = false;
        while(!q.empty())
        {
            vector<int> order;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                order.push_back(node->val);
                if(node -> left != NULL) q.push(node->left);
                if(node -> right != NULL) q.push(node->right);
                q.pop();
            }
            if(zigzag) reverse(order.begin(), order.end());
            ans.push_back(order);
            zigzag = !zigzag;
        }

        return ans;
    }
};
