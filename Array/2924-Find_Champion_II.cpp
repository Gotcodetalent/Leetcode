/*
題目：
https://leetcode.com/problems/find-champion-ii/description/

解說：
解題概念為等價類(equivalent class)
edge(u,v)代表team u勝過team v, 根據比賽結果將最終贏家記錄在root中
root初始值為-1,輸家的root被記錄成贏家,每比一次就更新一次root,使得地毯搜尋每個人的root便可知道誰是最終贏家
最終贏家的root值會是-1,最後只需檢查root值為-1的數目是否恰好為1

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int findroot(int u, vector<int>& root)
    {
        while(root[u] >= 0) u = root[u];
        return u;
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> root(n,-1);
        for(auto& edge: edges) root[edge[1]] = findroot(edge[0], root);           

        int champ_count = 1;
        int champ = findroot(0, root);

        for(int i=1; i<n; i++)
        {
            if(findroot(i, root) != champ)
            {
                champ = i;
                champ_count++;
            }
        }

        if(champ_count > 1) return -1;
        else return champ;

    }
};
