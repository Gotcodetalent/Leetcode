/*
題目：
https://leetcode.com/problems/minimum-window-substring/

解說：
當找到一組可能解時, 縮小 window 大小(left往前), 直到目前的位置, 不斷滑動直到 window 抵達邊界

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string minWindow(string s, string t) {
        int t_len = t.length();
        int s_len = s.length();

        if(s_len < t_len) return "";

        unordered_map<char,int> t_freq;
       
        for(char ch : t) t_freq[ch]++;
        unordered_map<char,int> s_freq;

        int l = 0, r = 0, cnt = 0, start = 0, mn = INT_MAX;
        while(r < s_len)
        {
            ++s_freq[s[r]];
            if(s_freq[s[r]] <= t_freq[s[r]]) cnt++;
            while(l <= r && cnt == t_len) {
                if(r - l + 1 < mn)
                {
                    start = l;
                    mn = r-l+1;
                }

                s_freq[s[l]]--;

                if(t_freq.count(s[l]) && s_freq[s[l]] < t_freq[s[l]]) cnt--;
                l++;
            }
            r++;
        }


        return mn == INT_MAX ? "" : s.substr(start, mn);
    }
};
