/*
題目：
https://leetcode.com/problems/n-queens-ii/

解說：
優化:
對角線檢查法
colUsed: 記錄已被使用的列，長度為 n。
d1Used: 記錄左上到右下的對角線，長度為 2 * n - 1。
d2Used: 記錄右上到左下的對角線，長度為 2 * n - 1。
在每次放置皇后, 會立即更新相關的列和對角線狀態,並且在遞迴返回時恢復狀態, 減少遞迴次數。

第一版:
從第一個row開始逐個col放置皇后,當遇到可以放置的便記錄下來並往下個遞,尋找下一列能擺放的位置 (line 60:前往遞迴後,擺放的位置要重置以供其他col測試)

有使用到的觀念：

*/

// #include "../code_function.h"
優化:
class Solution {
public:
    int ans = 0;
    
    void dfs(int n, int row, vector<int>& colUsed, vector<int>& d1Used, vector<int>& d2Used) {
        if (row == n) {
            ++ans;
            return;
        }
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (colUsed[col] || d1Used[d1] || d2Used[d2]) continue; // 跳過已經被使用的列和對角線
            colUsed[col] = d1Used[d1] = d2Used[d2] = 1;
            dfs(n, row + 1, colUsed, d1Used, d2Used);
            colUsed[col] = d1Used[d1] = d2Used[d2] = 0; // 回溯
        }
    }

    int totalNQueens(int n) {
        vector<int> colUsed(n, 0), d1Used(2 * n - 1, 0), d2Used(2 * n - 1, 0);
        dfs(n, 0, colUsed, d1Used, d2Used);
        return ans;
    }
};


第一版:
class Solution {
public:
    int ans = 0;
    bool isValid(int n,int row,int col,vector<vector<int>>& puzzle)
    {
        bool valid = true;
        for(int i=0; i<n; i++) //上下左右
        {
            if(puzzle[row][i]) valid = false;
            if(puzzle[i][col]) valid = false;
        }
        for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) //左上
        {
            if(puzzle[i][j]) valid = false;
        }
        for(int i = row-1,j = col+1; i >= 0 && j < n; i--,j++) //右上
        {
            if(puzzle[i][j]) valid = false;
        }
        // for(int i = row+1,j = col+1; i < n && j < n; i++,j++) //右下
        // {
        //     if(puzzle[i][j]) valid = false;
        // }
        // for(int i = row+1,j = col-1; i < n && j >= 0; i++,j--) //左下
        // {
        //     if(puzzle[i][j]) valid = false;
        // }


        return valid;
    }
    
    void dfs(int n, int start, vector<vector<int>>& puzzle){
        if(n == 0){
            ++ans;
            return;
        }
        for(int i=start; i<puzzle.size(); i++)
        {
            int row = i;
            for(int j=0; j<puzzle.size(); j++){
                int col = j;
                if(isValid(puzzle.size(),row,col,puzzle))
                {
                    puzzle[row][col] = 1;
                    dfs(n - 1, row+1, puzzle);
                    puzzle[row][col] = 0;
                }
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> puzzle(n,vector<int>(n,0));
        dfs(n,0,puzzle);
        return ans;
    }
};
