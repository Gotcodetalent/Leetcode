/*
題目：
https://leetcode.com/problems/basic-calculator/

解說：
使用 sign 代表目前要進行的運算, num 代表目前觀察到的數值
result 儲存目前所在的括弧內累計的數值, 當有左括弧出現時, 代表要計算新括弧的累計
先將當前 result & ops 給 push 到 stack 內, 直到遇到右括弧時, 再從 stack 中把儲存的值加回來
若遍歷到s的最後一個元素, 則再執行一次result更新


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
