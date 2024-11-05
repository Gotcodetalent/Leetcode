/*
題目：
https://leetcode.com/problems/longest-palindromic-substring/

解說：
針對 s 中的每一個字元，以該字元為中心先向右尋找與字元不同值的位置,接著再從左檢查是否符合回文條件。

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        int max_len = 0;
        int start = 0;

        for(int i=0; i<n ;i++)
        {
            int right = i;
            while(right < n && s[i] == s[right]) right++;

            int left = i-1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }

            int cur_len = (right -1) - (left + 1) + 1;

            if(max_len < cur_len)
            {
                max_len = cur_len;
                start = left + 1;
            }
        }

        return s.substr(start,max_len);
    }
};
