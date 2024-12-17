/*
題目：
https://leetcode.com/problems/min-stack/

解說：
實作一個 min stack 儲存 stack 中的 min value

有使用到的觀念：

*/

// #include "../code_function.h"

使用two stack (main, min):
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        mainStack.push(val);
    }
    
    void pop() {
        if(minStack.top() == mainStack.top())
        {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> minStack;
    stack<int> mainStack;
};

使用single stack:
class MinStack {
public:
    MinStack() {
        stackTop = -1;
        minval = INT_MAX;
    }
    
    void push(int val) {
        ++stackTop;
        vec.push_back(val);
        ++freq[val];
        if(minval > val) minval = val;
    }
    
    void pop() {
        if(stackTop == -1) return;

        --freq[vec[stackTop]]; 
        if(vec[stackTop] == minval && freq[vec[stackTop]] == 0)
        {
            minval = INT_MAX;
            for(int i = 0; i <= stackTop-1; i++) minval = min(minval, vec[i]);
        }
        vec.pop_back();
        --stackTop;
    }
    
    int top() {
        return vec[stackTop];
    }
    
    int getMin() {
        return minval;
    }

private:
    int stackTop;
    vector<int> vec;
    int minval;
    unordered_map<int, int> freq;
};
