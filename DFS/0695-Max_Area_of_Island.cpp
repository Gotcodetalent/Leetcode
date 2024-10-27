/*
題目：
https://leetcode.com/problems/max-area-of-island/description/

解說：
DFS找出最大島嶼面積,走過設為0

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> dir = {1,0,-1,0,1};
    int m,n;
    int MaxArea;
    int dfs(vector<vector<int>>& grid,int x, int y){
        if(grid[x][y] == 0) return 0; 
        grid[x][y] = 0;
        int sum = 1;
        for(int i=0; i<4; i++)
        {
            int xn = x + dir[i];
            int yn = y + dir[i+1];
            if(xn < 0 || yn < 0 || xn >= m || yn >= n || grid[xn][yn] == 0) continue;
            sum += dfs(grid,xn,yn);
        }
        MaxArea = max(MaxArea,sum);

        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int ret = dfs(grid,i,j);
            }
        }
        return MaxArea;
    }
};
