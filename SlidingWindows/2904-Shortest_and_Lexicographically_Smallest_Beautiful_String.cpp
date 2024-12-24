/*
題目：
https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

解說：
cnt 為 k 時與最小字串 ans 進行比較,比較完後 window 開始向左縮減 (l++) ,直到碰到下一個 1 為止

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0, r=0, cnt = 0;
        int minlen = INT_MAX;
        string ans = "";
        while(r < s.size())
        {
            if(s[r] == '1') ++cnt;
            while(cnt == k)
            {
                if(r-l+1 <= minlen)
                {
                    if(ans == "") ans = s.substr(l, r-l+1);
                    else {
                        if(r-l+1 < minlen) ans = s.substr(l, r-l+1);
                        else if(r-l+1 == minlen) ans = s.substr(l, r-l+1) < ans ? s.substr(l, r-l+1) : ans;
                    }
                    minlen = r-l+1;
                }

                if(s[l] == '1') cnt--;
                l++;

            }
            r++;
        }

        return ans;
    }
};
