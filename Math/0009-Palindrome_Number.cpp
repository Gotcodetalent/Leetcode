/*
題目：
https://leetcode.com/problems/palindrome-number/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isPalindrome(int x) {
        string integer = to_string(x);
        int size = integer.length();
        for(int i=0; i<size/2; i++)
        {
            if(integer[i] != integer[size-i-1]) return false;
        }

        return true;
    }
};
