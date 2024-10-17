/*
題目：
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

解說：
方法1: 先用以root為起點跑一次BFS,求出每個node的neighbor,接著再以target為起始點跑一次BFS,找到所有滿足distance為k的node
方法2: Recursive

有使用到的觀念：

*/

// #include "../code_function.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
Method 1:
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,vector<TreeNode*>> neighbors;
        unordered_map<TreeNode*,bool> visited;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left != NULL) {
                    q.push(node -> left);
                    neighbors[node].push_back(node->left);
                    neighbors[node->left].push_back(node);
                }
                if(node -> right != NULL) {
                    q.push(node -> right);
                    neighbors[node].push_back(node->right);
                    neighbors[node->right].push_back(node);
                }
            }
        }

        int distance = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(distance == k) ans.push_back(node -> val);
                for(auto& neighbor : neighbors[node])
                {
                    if(!visited[neighbor]) {
                        visited[neighbor] = true; 
                        q.push(neighbor);
                    }
                }
            }   
            distance++;
        }

        return ans;
    }
};

Method 2:
