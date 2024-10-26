/*
題目：
https://leetcode.com/problems/number-of-islands/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        vector<int> dir = {1,0,-1,0,1};
        for(int i=0; i<4; i++)
        {
            int xn = x + dir[i];
            int yn = y + dir[i+1];
            if(xn < 0 || yn < 0 || xn >= grid.size() || yn >= grid[0].size()) continue; 
            if(grid[xn][yn] == '1') {
                int tmp = dfs(xn,yn,grid);
            }
        }

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size();i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1') ans += dfs(i,j,grid);
            }
        }
        return ans;
    }
};
