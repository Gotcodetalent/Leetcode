/*
題目：
https://leetcode.com/problems/power-of-three/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1 && n%3 == 0){
            n/=3;
        }

        return n == 1;
    }
};
