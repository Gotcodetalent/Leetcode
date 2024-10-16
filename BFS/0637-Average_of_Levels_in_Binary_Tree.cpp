/*
題目：
https://leetcode.com/problems/average-of-levels-in-binary-tree/description

解說：
求Binary tree每個level元素的avg

有使用到的觀念：
BFS
*/

// #include "../code_function.h"
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            double sum = 0;
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                sum += node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                q.pop();
            }
            ans.push_back(sum/n);
        }
        
        return ans;
    }
};
