/*
題目：
https://leetcode.com/problems/shortest-path-visiting-all-nodes/

解說：
要使用BFS求最短的遍歷路徑,不能只單純記錄走過的node,而是要記錄走過的"path",且根據start node(或end node)來為相同的path做出區別
利用bitmap表示每個node可能走過的路徑,若有n個node,則有2^n種可能的路徑
將路徑作為index,使用2d vector visited來表示從node n開始的路徑中有那些是已經走訪過的
例如n = 4, node = {0,1,2,3},start node為0, 則走過[0,1,3]這三個節點的路徑為1101 (start node可能也為1,3),則visited[0][13(1101)] = 1
最短路徑即為最早蒐集到所有路徑時(即2^n-1)的step數

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        const int key = (1 << n) - 1;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(1 << n));
        for(int i=0; i<n; i++) q.push({i,(1 << i)});
        int step = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int> p = q.front();
                q.pop();

                int node = p.first;
                int path = p.second;
                if(path == key) return step;
                if(visited[node][path]) continue;
                visited[node][path] = 1;
                for(int next : graph[node])
                {
                    q.push({next, path | (1 << next)});
                } 
            }
            ++step;
        }

        return step;
    }
};
