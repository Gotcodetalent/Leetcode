/*
題目：
https://leetcode.com/problems/factorial-trailing-zeroes/

解說：
在階乘中，2 的數量總是比 5 多，因此尾隨零的數量只由 5 的次數決定。
因此計算 n 中可以提供 1 個 5, 2 個 5 ...所有能提供 5 的數之個數即可 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while (n >= 5) { 
            sum += (n / 5); // 計算 n 中有多少個完整的 5
            n /= 5;         // 繼續處理更高次方的 5（例如，25 = 5 × 5）
        }
        return sum;
    }
};
