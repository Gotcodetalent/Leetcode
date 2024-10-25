/*
題目：
https://leetcode.com/problems/word-search/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int x, int y, string word, int start, vector<vector<bool>>& visited) {
        if(start == word.length()) return true;
        vector<int> dir = {1,0,-1,0,1};
        visited[x][y] = true;
        for(int i=0; i<4; i++){
            int xn = x + dir[i];
            int yn = y + dir[i+1];
            if(xn < 0 || yn < 0 || xn >= board.size() || yn >= board[0].size()) continue;
            if(board[xn][yn] == word[start] && !visited[xn][yn]) {
                if(dfs(board,xn, yn, word, start+1, visited)) return true; 
            }
        }

        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((board[i][j] == word[0]) && dfs(board,i,j,word,1,visited)) return true;
            }
        }

        return false;
    }
};
