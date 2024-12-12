/*
題目：
https://leetcode.com/problems/first-unique-character-in-a-string/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ump;
        for(int i=0; i<s.length(); i++)
        {
            ump[s[i]]++;
        }
        
        for(int i=0; i<s.length(); i++)
        {
            if(ump[s[i]] == 1) return i;
        }

        return -1;
    }
};
