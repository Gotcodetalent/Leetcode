/*
題目：
https://leetcode.com/problems/ransom-note/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ump;
        for(char ch : magazine) ump[ch]++;
        for(char ch : ransomNote) {
            if(ump.count(ch)) --ump[ch];
            else return false;

            if(ump[ch] == 0) ump.erase(ch);
        }

        return true;
    }
};
