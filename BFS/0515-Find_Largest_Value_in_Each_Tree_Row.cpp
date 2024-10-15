/*
題目：
https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

解說：
BFS加入max值的比較

有使用到的觀念：
BFS
*/

// #include "../code_function.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int max = INT_MIN;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                if(node -> val > max) max = node -> val;
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
                q.pop();
            }
            ans.push_back(max);
        }

        return ans;
    }
};
