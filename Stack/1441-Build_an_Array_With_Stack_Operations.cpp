/*
題目：
https://leetcode.com/problems/build-an-array-with-stack-operations/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr = 0, stream = 1;
        int size = target.size();
        stack<int> stk;
        vector<string> ops;
        while(stream <= n)
        {
            if(curr == size) break;
            if(stream == target[curr]) {
                while(!stk.empty() && find(target.begin(), target.end(),stk.top()) == target.end()) {
                    stk.pop();
                    ops.push_back("Pop");
                }
                stk.push(stream);
                ops.push_back("Push");
                ++curr;
            }
            else {
                stk.push(stream);
                ops.push_back("Push");
            }
            ++stream;
        }

        return ops;
    }
};
