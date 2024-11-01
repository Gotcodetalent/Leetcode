/*
題目：
https://leetcode.com/problems/critical-connections-in-a-network/

解說：
概念與找出圖論中的關節點相同
在 DFS 中使用四個數組，
visited：因為是無向圖需使用 visited 紀錄是否拜訪過，
order：紀錄dfs拜訪時的順序
low：初始化時為 low[node] = dfn[node]，紀錄 child 中能接觸到的最小時間點
parent：避免拜訪到 parent node

有使用到的觀念：

*/

// #include "../code_function.h"
    class Solution {
    public:
        vector<vector<int>> ans;
        int time = 0;
        void dfs(int node, vector<bool>& visited, vector<int>& parent, vector<int>& low, vector<int>& order, vector<vector<int>>& edges) {
            visited[node] = true;
            order[node] = low[node] = ++time;
            for(const auto next : edges[node])
            {
                if(next == parent[node]) continue;
                if(!visited[next])
                {
                    parent[next] = node;
                    dfs(next, visited, parent, low, order, edges);

                    if(low[next] > order[node]) ans.push_back({node,next});
                    low[node] = min(low[next],low[node]);
                }
                else low[node] = min(order[next],low[node]);
            }
        }
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> edges(n);
            for(const auto e : connections)
            {
                edges[e[0]].push_back(e[1]);
                edges[e[1]].push_back(e[0]);
            }

            vector<bool> visited(n,false);
            vector<int> parent(n,-1);
            vector<int> low(n,0);
            vector<int> order(n,0);

            for(int i=0; i<n; i++)
            {
                if(!visited[i]) dfs(i,visited,parent,low,order,edges);
            }

            return ans;

        }
    };
