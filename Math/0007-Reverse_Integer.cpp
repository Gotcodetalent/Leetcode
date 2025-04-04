/*
題目：
https://leetcode.com/problems/reverse-integer/description/

解說：
反轉整數, 範圍是 INT_MAX ~ INT_MIN
逐個將餘數加上並*10

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while(x)
        {
            int digit = x%10;
            x/=10;
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10) return 0;

            reverse = reverse*10 + digit;
        }

        return reverse;
    }
};
