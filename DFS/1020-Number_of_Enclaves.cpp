/*
題目：
https://leetcode.com/problems/number-of-enclaves/

解說：
從邊界DFS,若可以走到就設定為0, 最後查看有多少個1

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int m,n;

    vector<int> dir{1,0,-1,0,1};
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if(grid[x][y] == 0) return;
        grid[x][y] = 0;
        for(int i=0; i<4; i++)
        {
            int xn = x + dir[i];
            int yn = y + dir[i+1];
            if(xn < 0 || yn < 0 || xn >= m || yn >= n) continue;
            dfs(grid,x + dir[i], y + dir[i+1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++)
        {
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        } 
        for(int j=0; j<n; j++)
        {
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        } 

        int remaining = 0;

        for(int i=0; i<m ;i++){
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]) ++remaining;
            }
        }

        return remaining;
    }
};
