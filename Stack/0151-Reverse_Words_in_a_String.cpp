/*
題目：
https://leetcode.com/problems/reverse-words-in-a-string/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ') continue;
            string str = "";
            while(i < s.length() && s[i] != ' ')
            {
                str += s[i];
                i++;
            }
            words.push(str);
        }

        string ans = words.top();
        words.pop();
        while(!words.empty())
        {
            ans = ans + " " + words.top();
            words.pop();
        }

        return ans;
    }
};
