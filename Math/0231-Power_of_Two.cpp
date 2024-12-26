/*
題目：
https://leetcode.com/problems/power-of-two/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int power = 1;
        while(n>1 && n%2==0)
        {
            n/=2;
        }

        return 1 == n;
    }
};
