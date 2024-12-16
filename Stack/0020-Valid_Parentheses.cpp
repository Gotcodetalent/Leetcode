/*
題目：
https://leetcode.com/problems/valid-parentheses/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else{
                if(ch == ')')
                {
                    if(!stk.empty() && stk.top() == '(') stk.pop();
                    else return false;
                }
                else if(ch == ']')
                {
                    if(!stk.empty() && stk.top() == '[') stk.pop();
                    else return false;
                }
                else if(ch == '}')
                {
                    if(!stk.empty() && stk.top() == '{') stk.pop();
                    else return false;
                }
            }
        }

        if(stk.empty()) return true;
        else return false;
    }
};
