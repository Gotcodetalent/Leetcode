/*
題目：
https://leetcode.com/problems/power-of-four/

解說：
n & (n-1) == 0 用於確認是否為 2 的倍數
0x55555555 -> 0101 0101 0101 0101 0101 0101 0101 0101
因為是四的倍數，因此只會在偶數位置上會是 1 奇數位置上為 0

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

class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        return n > 0 && ((n & (n-1)) == 0) && (n & 0x55555555);
    }
};
