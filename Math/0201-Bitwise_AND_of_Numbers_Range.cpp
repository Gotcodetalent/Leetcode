/*
題目：
https://leetcode.com/problems/bitwise-and-of-numbers-range/

解說：
left 與 right 有 common prefix 時, bitwise and 才會有結果, 否則為 0

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        // 找到共同前綴
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }

        // 將共同前綴左移回原位置
        return left << shift;
    }
};
