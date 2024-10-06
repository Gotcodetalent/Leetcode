/*
題目：
https://leetcode.com/problems/construct-product-matrix/

解說：
先計算出左邊乘積再計算出右邊乘積(要先do module,否則即使用long long型態heap也會overflow), 最後再乘在一起

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        const long long MOD = 12345;
        vector<long long> product_l(n*m, 1);
        vector<long long> product_r(n*m, 1);
        vector<vector<int>> ret(n, vector<int>(m, 1));
        for(int i=1 ;i<n*m; i++){
            product_l[i] = grid[(i - 1)/m][(i - 1)%m] * product_l[i - 1] % MOD;
        }
        for(int i=n*m-2; i>=0; i--){
            product_r[i] = grid[(i + 1)/m][(i + 1)%m] * product_r[i + 1] % MOD;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ret[i][j] = (product_l[i*m + j] * product_r[i*m + j]) % MOD;
            }
        }

        return ret;
    }
};
