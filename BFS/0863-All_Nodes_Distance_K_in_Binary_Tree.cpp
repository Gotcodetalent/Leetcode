/*
題目：
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

解說：
方法1: 先用以root為起點跑一次BFS,求出每個node的neighbor,接著再以target為起始點跑一次BFS,找到所有滿足distance為k的node
方法2: Recursive, 分為兩種情況
a.使用dist找到target後,先用collect找到以target為root時相距為k的node
b.當找到target時會return 0,若target在左子樹,則開始以target的parent node為root遞迴檢查與其相距為k的node, left的物理意義為target所在的level,初始為0
因此便從root的右子點(與root的左子點最小距離為2)找尋距離k-left-2的node,接著繼續往上遞迴(left+1)

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
class Solution {
    vector<int> ans;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        dist(root, target, k);
        return ans;
    }

    // return the distance from root to target
    // return -1 if target does not in the tree
    int dist(TreeNode* root, TreeNode* target, int k)
    {
        if(root == nullptr) return -1;
        if(root == target)
        {
            collect(target, k);
            return 0;
        }

        int left = dist(root->left, target, k);
        int right = dist(root->right, target, k);

        // target in the left subtree
        if(left >= 0)
        {
            if(left == k-1) ans.push_back(root->val);
            collect(root->right, k - left - 2);
            return left+1;
        }
        // target in the right subtree
        if(right >= 0)
        {
            if(right == k-1) ans.push_back(root->val);
            collect(root->left, k - right - 2);
            return right + 1;
        }

        return -1;
    }

    void collect(TreeNode* root, int d)
    {
        if(root == nullptr || d < 0) return;
        if(d == 0) ans.push_back(root->val);
        collect(root->left, d-1);
        collect(root->right, d-1);
    }
};
