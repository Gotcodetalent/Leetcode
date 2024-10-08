/*
題目：
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

解說：
s長度為even, 且符合的substr切割成最小單位後長度為2,因此只要兩兩判斷字元是否相同即可 ("00", "11")

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minChanges(string s) {
        const int n = s.size();
        int sum = 0;
        for(int i=1; i<n; i+=2)
        {
            if(s[i] == s[i-1]) continue;
            else sum++;
        }

        return sum;
    }
};
