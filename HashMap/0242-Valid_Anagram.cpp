/*
題目：
https://leetcode.com/problems/valid-anagram/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ump;
        for(char ch : s) ump[ch]++;
        for(char ch : t) {
            if(ump.count(ch))
            {
                --ump[ch];
                if(ump[ch] == 0) ump.erase(ch);
            }   
            else return false;
        }

        return ump.empty();
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
