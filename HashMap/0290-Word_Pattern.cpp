/*
題目：
https://leetcode.com/problems/word-pattern/

解說：
split s, 找出要對應的word
建立Hash Table, 並把對應過的string記錄起來

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> list;
        unordered_map<char,string> ump;
        unordered_map<string,bool> used;
        split(list,s);
        
        if(list.size() != pattern.length()) return false;
        
        int i=0;
        for(char ch : pattern)
        {
            if(ump.count(ch)) {
                if(ump[ch] != list[i]) return false;
            }
            else {
                if(!used.count(list[i])) {
                    ump[ch] = list[i];
                    used[list[i]] = true;
                }
                else return false;
            }
            i++;
        }

        return true;
    }

    void split(vector<string>& list, string s)
    {
        int i=0;
        while(i < s.length())
        {
            string str = "";
            while(s[i] != ' ' && i < s.length()) {
                str += s[i];
                i++;
            }
            list.push_back(str);
            i++;
        }
    }
};
