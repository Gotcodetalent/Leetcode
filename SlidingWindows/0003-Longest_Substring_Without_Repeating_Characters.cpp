/*
題目：
https://leetcode.com/problems/longest-substring-without-repeating-characters/


解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int head = 0;
        int mx = 0;
        for(int i=0; i<s.length(); i++)
        {
            ++ump[s[i]];
            if(ump[s[i]] > 1)
            {
                while(ump[s[i]] != 1)
                {
                    --ump[s[head]];
                    ++head;
                }
            }
            mx = max(mx, i - head + 1);
        }

        return mx;
    }
};
