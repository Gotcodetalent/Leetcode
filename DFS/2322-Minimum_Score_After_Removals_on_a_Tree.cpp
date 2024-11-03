/*
題目：
https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/

解說：
題目敘述：給予一個無向連通圖, 刪除兩個edge後形成三個component,在每個component中將所有node內的值一起做xor運算
將三者之中最大值減去最小值即為一個可能解, 求最小可能解

把一個邊去掉後,就會形成兩個component x & y
因此剩下一個component勢必由 x or y中分離出來
所以只要對每個邊集中的邊進行去除後,從x與y中各遍歷一次,來尋找所有可能解
最後將2種可能進行比較得出最小值即可
solve：從a為首的component中找尋可能解並返回最小值
getAll：得到以node為root時的xor結果
dfs：從x or y中找尋所有可能的第三個component並比較

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

            int C = dfs(next, ret, A, B); //返回以子點為root的xor結果
            int other = A^C; //排除第三個component後, A的xor結果
            int mx = max(other, max(C, B)); //找當前最大值
            int mn = min(other, min(C, B)); //找當前最小值
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
