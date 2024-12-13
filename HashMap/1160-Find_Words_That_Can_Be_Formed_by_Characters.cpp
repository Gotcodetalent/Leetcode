/*
題目：
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> ump;
        for(char ch : chars) ump[ch]++;

        int good = 0;
        for(string str : words) good += check(str, ump);

        return good;
    }

    int check(string str, unordered_map<char,int> ump)
    {
        for(char ch : str)
        {
            if(!ump.count(ch)) return 0;
            else --ump[ch];

            if(ump[ch] == 0) ump.erase(ch);
        }

        return str.length();
    }
};
