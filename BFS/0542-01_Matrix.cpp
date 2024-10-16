/*
題目：
https://leetcode.com/problems/01-matrix/

解說：
在0-1 Matrix中,求出每一格到數字'0'的距離,若本身為0距離為0
使用BFS從左上到右下、右下到左上各掃過一次即可得到最佳解
只從左上或右下掃一次只能得到local optimal

有使用到的觀念：
BFS
*/

// #include "../code_function.h"
較簡潔的寫法:
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX/2));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0) dist[i][j] = 0;
                else
                {
                    if(i > 0) 
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }

        for(int i = m-1; i >= 0; i--)
            for(int j = n-1; j >= 0; j--)
            {
                if(i < m-1)
                    dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                if(j < n-1)
                    dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
            }

        return dist;
    }
};


第一次寫的解法:
class Solution {
public:
    bool isValid_row(int x, int m) {
        return (x >= 0 && x < m);
    }
    bool isValid_col(int x, int n) {
        return (x >= 0 && x < n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX/2));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    for(auto& pair : direction) {
                        int x = i + pair.first;
                        int y = j + pair.second;
                        if(isValid_row(x, m) && isValid_col(y, n)) {
                            if(mat[x][y] == 0) {
                                dist[i][j] = 1;
                            } else {
                                dist[i][j] = min(dist[i][j], dist[x][y] + 1);
                            }
                        }
                    }
                }
                
                if(mat[m-i-1][n-j-1] == 0) {
                    dist[m-i-1][n-j-1] = 0;
                } else {
                    for(auto& pair : direction) {
                        int x = m-i-1 + pair.first;
                        int y = n-j-1 + pair.second;
                        if(isValid_row(x, m) && isValid_col(y, n)) {
                            if(mat[x][y] == 0) {
                                dist[m-i-1][n-j-1] = 1;
                            } else {
                                dist[m-i-1][n-j-1] = min(dist[m-i-1][n-j-1], dist[x][y] + 1);
                            }
                        }
                    }
                }
            }
        }

        return dist;
    }
};
