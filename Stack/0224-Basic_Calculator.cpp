/*
題目：
https://leetcode.com/problems/basic-calculator/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<int> ops;
        int num = 0;
        int sign = 1;
        int result = 0;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            if(isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }

            if(!isdigit(ch) && ch != ' ' || i == s.length() - 1)
            {
                result += sign * num;
                num = 0;

                if(ch == '+') sign = 1;
                else if(ch == '-') sign = -1;
                else if(ch =='(')
                {
                    nums.push(result);
                    ops.push(sign);
                    result = 0;
                    sign = 1;
                }
                else if(ch == ')')
                {
                    result = nums.top() + ops.top() * result;
                    nums.pop();
                    ops.pop();
                }
            }
        }

        return result;
    }
};
