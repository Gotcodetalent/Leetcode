/*
題目：
https://leetcode.com/problems/number-of-1-bits/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n)
        {
            if(n % 2 == 1) ++cnt;
            n/=2;
        }

        return cnt;
    }
};
