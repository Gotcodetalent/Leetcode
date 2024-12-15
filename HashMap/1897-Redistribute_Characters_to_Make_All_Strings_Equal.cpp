/*
題目：
https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> ump;
        for(string str : words)
        {
            for(char ch : str)
            {
                ump[ch]++;
            }
        }

        int n = words.size();
        for(auto& p : ump)
        {
            if((p.second % n) > 0) return false;
        }

        return true;
    }
};
