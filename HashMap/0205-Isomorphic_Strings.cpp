/*
題目：
https://leetcode.com/problems/isomorphic-strings/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ump;
        unordered_map<char, int> used;
        for(int i=0; i<t.length(); i++) 
        {
            if(ump.count(t[i])) continue;
            else{
                if(!used.count(s[i])){
                    ump[t[i]] = s[i];    
                    used[s[i]] = 1;
                }
            }
        }

        for(int i=0; i<t.length(); i++) 
        {
            if(ump[t[i]] != s[i]) return false;
        }

        return true;
    }
};
