/*
題目：
https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/

解說：
cond 1. && cond 2.
字串 a, b 都是由26種字母組成, 因此要確保 a 的字元皆小於 b
可以使 a 中原本是('a' ~ '[curr - 1]')必小於 b 中的字元, 同時確保 b 中原本是('[curr]' ~ 'z')的字元必大於 a 中的字元 -> 以curr為邊界切割
即 組成 a 的所有字元都會小於 b 中的字元

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> cnt_a(26,0);
        vector<int> cnt_b(26,0);
        for(char& ch : a) cnt_a[ch-'a']++;
        for(char& ch : b) cnt_b[ch-'a']++;

        int ans = INT_MAX/2;

        for(int curr = 0; curr < 26; curr++)
        {
            int change = 0;
            if(curr > 0)
            {
                // cond 1.
                for(int i=0; i<curr; i++) change += cnt_b[i];
                for(int i=curr; i<26; i++) change += cnt_a[i];
                ans = min(ans, change);
                
                change = 0;
                //cond 2.
                for(int i=0; i<curr; i++) change += cnt_a[i];
                for(int i=curr; i<26; i++) change += cnt_b[i];
                ans = min(ans, change);
            }

            //cond 3.
            change = 0;

            for(int i=0; i<26; i++)
            {
                if(i != curr)
                {
                    change += cnt_a[i];
                    change += cnt_b[i];
                }
            }

            ans = min(ans, change);
        }

        return ans;
    }
};
