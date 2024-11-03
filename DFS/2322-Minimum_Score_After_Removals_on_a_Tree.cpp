/*
題目：
https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int n;
    unordered_set<int> subtree[1005];
    vector<int> nums;
    bool visited[1005];
    
    int dfs(int node, int& ret, int A, int B) {
        int total = 0;
        for(int next: subtree[node])
        {
            if(visited[next] == 1)continue;
            visited[next] = 1;

            int C = dfs(next, ret, A, B);
            int other = A^C;
            int mx = max(other, max(C, B));
            int mn = min(other, min(C, B));
            ret = min(ret, mx-mn);

            total ^= C;
        }
        total ^= nums[node];
        return total;
    }
    
    int getAll(int node) {
        int total = 0;

        for(int neighbor : subtree[node])
        {
            if(visited[neighbor]) continue;
            visited[neighbor] = true;
            total ^= getAll(neighbor);
        }

        total ^= nums[node];
        return total;
    }

    int solve(int a, int b) {
        fill(visited,visited+n,false);
        visited[a] = true;
        int A = getAll(a);

        fill(visited,visited+n,false);
        visited[b] = true;
        int B = getAll(b);

        int ret = INT_MAX;
        fill(visited,visited+n,false);
        visited[a] = 1;
        dfs(a,ret,A,B);

        return ret;
    }


    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->n = nums.size();
        this->nums = nums;
        for (auto& e : edges) {
            subtree[e[0]].insert(e[1]);
            subtree[e[1]].insert(e[0]);
        }

        int minScore = INT_MAX;

        for(auto e : edges)
        {
            int a = e[0], b = e[1];
            subtree[a].erase(b);
            subtree[b].erase(a);

            int ret1 = solve(a,b);
            int ret2 = solve(b,a);

            minScore = min(minScore, min(ret1, ret2));

            subtree[a].insert(b);
            subtree[b].insert(a);
        }

        return minScore;
    }
};
