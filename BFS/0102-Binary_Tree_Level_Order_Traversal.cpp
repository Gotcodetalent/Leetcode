/*
題目：
https://leetcode.com/problems/binary-tree-level-order-traversal/

解說：
利用BFS求level order,首先插入第一個節點,當queue不為null時,代表該level有可以輸出的order
對於每一層的每個非空節點 x,將其value插入tmp中,接著將x->left, x->right插入queue中,探索完後刪除 x。
由tmp所組成的ans即為所有level的order

有使用到的觀念：
BFS, Tree
*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        vector<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty())
        {
            vector<int> tmp;
            int size = queue.size();
            for(int i=0; i<size; i++)
            {
                tmp.push_back(queue[0]->val);
                if(queue[0] -> left != NULL) queue.push_back(queue[0]->left);
                if(queue[0] -> right != NULL) queue.push_back(queue[0]->right);
                queue.erase(queue.begin());
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
