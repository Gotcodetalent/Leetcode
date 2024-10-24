/*
題目：
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,bool>>> neighbors;
        for(auto& connect : connections)
        {
            neighbors[connect[0]].push_back({connect[1],true}); //need to change direction
            neighbors[connect[1]].push_back({connect[0],false});
        }

        vector<bool> reach(n, false);
        queue<int> q;
        q.push(0);
        reach[0] = true;
        int change = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto& neighbor : neighbors[node])
            {
                if(!reach[neighbor.first])
                {
                    reach[neighbor.first] = true;
                    q.push(neighbor.first);
                    if(neighbor.second) ++change;
                }
            }
        }

        return change;
    }
};
