/*
題目：
https://leetcode.com/problems/is-graph-bipartite/

解說：
對於任意一個定點，將他歸納為 A 組，那與該點相鄰的點必定都要歸入 B，而該點相鄰的點其相鄰點會被歸入為 A 組。
因此從 node 0 開始做 BFS 遍歷，擴展時 A/B組交替標記。
如果在標記過程中遇到已經分組的節點，檢查是否有矛盾之處，比如接續要標記 A 但已經被標記成 B，此處就是矛盾之處，如果有就返回False
另外, 已經標記過的點代表已經被加入queue中, 因此不必再額外檢查


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> group(graph.size(),-1);
        queue<int> q;
        for(int i=0; i<graph.size(); i++) 
        {
            if(group[i] == -1){
                group[i] = 0;
                q.push(i);
            }
            else continue;
        
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int neighbor: graph[node])
                {
                    if(group[neighbor] == -1) {
                        group[neighbor] = group[node] ^ 1;
                        q.push(neighbor);
                    }
                    else if(group[node] == group[neighbor]) return false;
                }
            }
        }

        return true;
    }
};
