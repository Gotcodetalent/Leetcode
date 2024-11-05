/*
題目：
https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/

解說：
題目是在說,給定一個無向連通tree,有n個nodes, n-1條edges
可以從tree中拿取任意node之value並加總(sum),隨後將該node之value設定為0,但必須確保：
** root (0) 到任一leaf上所有node value不能全為0

找出滿足此條件下,所有路徑上的value加總之最大值

- 解題思路: 
要找最大值且每條路徑不能全為0,就是要找出路徑上最小值的意思
因此只要dfs找出路徑上最小值的總和, 最後以全部value的總和減去後即為所求的最大值


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vals;
    struct subtree{
        long long min_sum;
        long long total_sum;
    };
    subtree dfs(int node, int parent) {
        subtree t;
        t.min_sum = 0;
        t.total_sum = vals[node];
        for(const auto neighbor : graph[node])
        {
            if(neighbor != parent)
            {
                subtree tmp = dfs(neighbor, node);
                t.min_sum += tmp.min_sum;;
                t.total_sum += tmp.total_sum;
            }
        }

        if(t.min_sum == 0) t.min_sum = vals[node]; // leaf
        else t.min_sum = min<long long>(t.min_sum, vals[node]);

        return t;
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        this->vals = values;
        graph.resize(values.size());
        long long ans = 0;
        
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        auto t = dfs(0, -1);
        ans = t.total_sum - t.min_sum;
        return ans;
    }
};
