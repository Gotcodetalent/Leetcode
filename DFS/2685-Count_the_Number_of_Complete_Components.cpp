/*
題目：
https://leetcode.com/problems/count-the-number-of-complete-components/description/

解說：
判斷給定圖中有幾個 complete connected components, complete 代表 connected component 中的每個 vertex 彼此之間有 edge 相連
step 1. 建立graph
step 2. 執行 DFS 來找出 connected compenent
step 3. 判斷 connected component 中有哪些是 complete 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n);
        visited = vector<bool>(n,false);
        
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; ++i)
        {
            if (visited[i]) 
            {
                continue;
            }
            vector<int> tmp;
            dfs(i,tmp);
            components.push_back(tmp);
        }

        int ans = 0;

        for(auto& c : components)
        {
            if(check(c, edges))
            {
                ++ans;    
            }
        }
        
        return ans;
    }

private:
    vector<bool> visited;
    vector<vector<int>> components;
    vector<vector<int>> graph;

    void dfs(int node, vector<int>& component)
    {
        visited[node] = true;
        component.push_back(node);
        for(auto& v : graph[node])
        {
            if(!visited[v]) 
            {
                dfs(v, component);
            }
        }
        
        return;
    }
    
    bool check(vector<int>& component, vector<vector<int>>& edges)
    {
        for (int i = 0; i < component.size(); ++i)
        {
            int start = component[i];
            for(int j = i + 1; j < component.size(); ++j)
            {
                if(find(graph[start].begin(), graph[start].end(), component[j]) == graph[start].end())
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
