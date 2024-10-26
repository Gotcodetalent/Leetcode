/*
題目：
https://leetcode.com/problems/pacific-atlantic-water-flow/

解說：
從pacific, atlantic的邊界開始尋找能匯流到的點,即heights[xn][yn] > heights[x][y],並標記起來
若對於兩個海都能夠匯流便是答案

有使用到的觀念：
DFS
*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pacific, atlantic;
    int m ,n;
    vector<int> dir = {1,0,-1,0,1};

    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<int>>& ocean) {
        ocean[x][y] = 1;
        for(int i=0; i<4; i++)
        {
            int xn = x + dir[i];
            int yn = y + dir[i+1];
            if(xn < 0 || yn < 0 || xn >= m || yn >= n || ocean[xn][yn] || heights[xn][yn] < heights[x][y]) continue;
            dfs(xn,yn,heights,ocean);
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        pacific = vector<vector<int>>(m, vector<int>(n,0));
        atlantic = vector<vector<int>>(m, vector<int>(n,0));

        for(int i=0; i<m; i++)
        {
            dfs(i,0,heights,pacific);
            dfs(i,n-1,heights,atlantic);
        }

        for(int j=0; j<n; j++)
        {
            dfs(0,j,heights,pacific);
            dfs(m-1,j,heights,atlantic);
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
