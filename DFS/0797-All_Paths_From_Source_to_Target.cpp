/*
題目：
https://leetcode.com/problems/all-paths-from-source-to-target/

解說：
DFS找尋所有可能路徑

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& graph, int start, vector<int>& vec) {
        vec.push_back(start); // 在進入節點時加入路徑
        
        if (start == graph.size() - 1) {
            ans.push_back(vec); // 到達終點時，直接存入結果
        } else {
            for (int j = 0; j < graph[start].size(); j++) {
                dfs(graph, graph[start][j], vec); // 遞迴
            }
        }
        
        vec.pop_back(); // 回溯時移除節點
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> vec;
        dfs(graph, 0, vec);
        return ans;
    }
};
