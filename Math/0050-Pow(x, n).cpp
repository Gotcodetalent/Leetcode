/*
題目：
https://leetcode.com/problems/powx-n/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;

        if(n < 0){
            x = 1/x;
            n = abs(n);
        }

        if(n % 2 == 0) return myPow(x*x, n/2);
        else return x*myPow(x*x, n/2);
    }
};
