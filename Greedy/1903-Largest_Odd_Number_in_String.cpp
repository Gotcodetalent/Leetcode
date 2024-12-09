/*
題目：
https://leetcode.com/problems/largest-odd-number-in-string/


解說：
先找到最小的奇數所在的位置

有使用到的觀念：
Greedy

*/

// #include "../code_function.h"
class Solution {
public:
    string largestOddNumber(string num) {
        const int n = num.length();
        string ans = "";
        bool findOdd = false;
        for(int i=n-1; i>=0; i--)
        {
            if(num[i] % 2 == 1) findOdd = true;
            if(findOdd) 
            {
                ans = num.substr(0,i+1);
                return ans;
            }
            
        }

        return ans;
    }
};
