/*
題目：
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

解說：
DFS中使用struct同時記錄左右子樹的size跟sum, 只要node與avg相同便++ans;

有使用到的觀念：

*/
class Solution {
public:
    int ans = 0;
    struct subtree{
        int sum;
        int size;
    };
    subtree dfs(TreeNode* node) {
        if(node == nullptr) return {0,0};

        subtree l = dfs(node -> left);
        subtree r = dfs(node -> right);
        int sum = l.sum + r.sum + node->val;
        int size = l.size + r.size + 1; 
        if((sum / size) == node->val) ++ans;

        return {sum, size};
    } 

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
