/*
題目：
https://leetcode.com/problems/number-of-closed-islands/

解說：
從(1,1)迭代到(m-2,n-2),若grid[i][j]不為0就跑dfs,走過的就設為1
能跑幾次即代表有幾個獨立的島嶼

有使用到的觀念：

*/

// #include "../code_function.h"
    class Solution {
    public:
        int m,n;
        vector<int> dir={1,0,-1,0,1};
        int dfs(int x, int y, vector<vector<int>>& grid){
            if(x < 0 || y < 0 || x >= m || y >= n) return 0; //測試越界
            if(grid[x][y] == 1) return 1;
            grid[x][y] = 1;
            int ret = 0;
            for(int i=0; i<4; i++)
            {
                ret += dfs(x + dir[i], y + dir[i+1], grid);
            }
            
            if(ret == 4) return 1;
            else return 0;  
            
        }

        int closedIsland(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size(); 
            int ans = 0;
            for(int i=1; i<m-1; i++)
            {
                for(int j=1; j<n-1; j++)
                {
                    if(grid[i][j] == 0){
                        if(dfs(i,j,grid)) ++ans;
                    }
                }
            }   

            return ans;
        }
    };
