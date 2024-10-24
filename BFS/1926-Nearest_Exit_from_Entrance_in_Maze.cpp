/*
題目：
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

解說：
BFS全部遍歷一次

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<vector<int>> q;
        q.push(entrance); 
        visited[entrance[0]][entrance[1]] = true;
        int steps = 1;
        vector<int> dir = {1,0,-1,0,1};

        while(!q.empty())
        { 
            int size = q.size();
            while(size--){  
                auto pair = q.front();
                int x = pair[0];
                int y = pair[1];
                q.pop(); 
                for(int i=0; i<4; i++)
                {
                    int xn = x + dir[i];
                    int yn = y + dir[i+1];
                    if(xn < 0 || xn >= m || yn < 0 || yn >= n) continue;
                    if(maze[xn][yn] != '+' && !visited[xn][yn])
                    {
                        if(xn == 0 || xn == m-1 || yn == 0 || yn == n-1) return steps;
                        visited[xn][yn] = true;
                        q.push({xn,yn});
                    }
                } 
            }
            ++steps;
        }

        return -1;
    }
};
