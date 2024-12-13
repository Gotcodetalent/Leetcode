/*
題目：
https://leetcode.com/problems/diagonal-traverse/description/

解說：
對角線
1. 左上到右下 : x-y相同
2. 右上到左下 : x+y相同

以hashmap將相同對角線元素放在一起,最後依序取出

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        unordered_map<int,int> ump;
        vector<vector<int>> diagonal_group;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ump.count(i+j)) diagonal_group[ump[i+j]].push_back(mat[i][j]);
                else {
                    ump[i+j] = diagonal_group.size();
                    diagonal_group.push_back({mat[i][j]});
                }
            }
        }

        vector<int> order;
        bool reverse = true;
        for(auto& group : diagonal_group)
        {
            int n = group.size();
            for(int i=n-1; i>=0; --i)
            {
                if(reverse) order.push_back(group[i]);
                else order.push_back(group[n-i-1]);
            }
            reverse = !reverse;
        }

        return order;
    }
};
