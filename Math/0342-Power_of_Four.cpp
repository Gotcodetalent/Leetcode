/*
題目：
https://leetcode.com/problems/power-of-four/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n > 1 && n%4 == 0){
            n/=4;
        }

        return n == 1;
    }
};
