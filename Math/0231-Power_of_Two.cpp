/*
題目：
https://leetcode.com/problems/power-of-two/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n > 0 && (n&(n-1))==0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1 && n%2==0)
        {
            n/=2;
        }

        return 1 == n;
    }
};
