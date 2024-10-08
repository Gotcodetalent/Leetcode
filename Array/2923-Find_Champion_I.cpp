/*
題目：
https://leetcode.com/problems/find-champion-i/description/

解說：
有n個team, 比賽結果只有win or lose,所以只要利用查表結果比較n-1次,就可以知道誰是champion (比較過程中贏的就設定為champ)

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        const int n = grid.size();;
        int champ = 0;
        for(int i=1; i<n ;i++)
        {
            if(grid[champ][i] == 0) champ = i;
        }

        return champ;
    }
};
