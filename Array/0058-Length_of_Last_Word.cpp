/*
題目：
https://leetcode.com/problems/length-of-last-word/

解說：
題目要找出最後一個substring的長度，所以先從最右邊移除空格，接著算出子字串的長度。

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), length = 0;
        while(n >= 0 && s[--n] == ' ' );
        while(n >= 0 && s[n--] != ' ') length++;
        return length;
    }
};
