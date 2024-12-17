/*
題目：
https://leetcode.com/problems/evaluate-reverse-polish-notation/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string str : tokens)
        {
            if(str != "+" && str != "-" && str != "*" && str != "/" ) nums.push(stoi(str));
            else{
                if(str == "+")
                {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    int c = a + b;
                    nums.push(c);
                }
                else if(str == "-")
                {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    int c = a - b;
                    nums.push(c);
                }
                else if(str == "*")
                {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    int c = a * b;
                    nums.push(c);
                }
                else{
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    int c = a / b;
                    nums.push(c);
                }
            }
        }

        return nums.top();
    }
};
