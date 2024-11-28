/*
題目：
https://leetcode.com/problems/daily-temperatures/submissions/1464646448/

解說：
使用Stack紀錄尚未找到warmer day的日期以及其溫度

有使用到的觀念：
stack

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> stack;
        for(int i=0; i<n; i++)
        {
            while(!stack.empty() && temperatures[i] > stack.top().first)
            {
                auto top = stack.top();
                stack.pop();
                ans[top.second] = i - top.second;
            }
            stack.push({temperatures[i],i});
        }

        return ans;
    }
};
