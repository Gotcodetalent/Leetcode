/*
題目：
https://leetcode.com/problems/count-nodes-with-the-highest-score/

解說：
求刪掉某個node後,產生的每個subtree數量的乘積
step 1. 建立圖
step 2. DFS找出以每個node為root時,其size為多少,並記錄下來
step 3. 左子樹size * 右子樹size * number of remaining nodes

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long max_num;
    int max_count;
    int dfs(int node, vector<vector<int>>& child, vector<int>& size) {
        if(node == -1) return 0;

        int cnt = 1;
        for(int ch : child[node]) cnt += dfs(ch,child,size);
        size[node] = cnt;

        return cnt;
    }
    void cal(int node, vector<vector<int>>& child, vector<int>& size,vector<int>& parents, int totalNodes){
        long long r = 1, l = 1, up = 1;
        if(child[node][0] != -1) r = size[child[node][0]];
        if(child[node][1] != -1) l = size[child[node][1]];
        if(parents[node] != -1) up = totalNodes - size[node];

        long long total = r*l*up;
        if(total > max_num){
            max_num = total;
            max_count = 1;
        }
        else if(total == max_num) max_count++;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        const int n = parents.size(); 
        vector<vector<int>> child(n,vector<int>(2,-1));
        vector<int> size(n,0);
        for(int i=1; i<n; i++) {
            if (child[parents[i]][0] == -1) child[parents[i]][0] = i;
            else child[parents[i]][1] = i;
        }

        int tmp = dfs(0,child,size);
        
        for(int i=0; i<n; i++)
        {
            cal(i,child,size,parents,n);
        }
    
        return max_count;
    }
};
