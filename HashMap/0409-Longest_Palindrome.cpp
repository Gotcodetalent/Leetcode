/*
題目：
https://leetcode.com/problems/longest-palindrome/

解說：
偶數全加, 奇數減一變為偶數後也可以加入
有奇數時,最後還能再加一個數到中間

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ump;
        for(char ch : s) ump[ch]++;
        bool Odd = false;
        int ans = 0;
        for(const auto& [key,val] : ump)
        {
            if(val % 2 == 1)
            {
                Odd = true;
                ans += val - 1;
            }
            else ans += val;
        }

        if(Odd) return ans+1;
        else return ans;
    }
};
