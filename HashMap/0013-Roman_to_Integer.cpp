/*
題目：
https://leetcode.com/problems/roman-to-integer/

解說：
如果 position i 對應的 value 大於 position i+1, 代表執行加法, 反之則為減法.

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        int ans = 0;
        s += 'I';
        for(int i=s.length()-1; i>=0; --i)
        {
            if(ump[s[i]] >= ump[s[i+1]]) ans += ump[s[i]];
            else if(ump[s[i]] < ump[s[i+1]]) ans -= ump[s[i]]; 
        }

        return ans;
    }
};
