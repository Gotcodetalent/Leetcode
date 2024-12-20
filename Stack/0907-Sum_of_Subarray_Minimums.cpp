/*
題目：
https://leetcode.com/problems/sum-of-subarray-minimums/

解說：
對於 arr[i] 找出 
1. 左邊小於自己的第一個值的位置 x (i-x 即 向左延伸時可支配的subarray數量)
2. 右邊小於等於自己的第一個值的位置 y (i-y 即 向右延伸時可支配的subarray數量)
left[i] * right [i] = arr[i] 可支配的 subarray總數

*左邊小於等於的原因是因為, 剛從左邊掃過來時的子陣列範圍是獨立的 (不重複), 但處理右邊時由於要確保子陣列範圍是獨立的
延伸邊界時遇到相同元素必須要停下來
ex: [...,3,2,1,1,...], 計算左邊數來第一個1的右邊界時如果加進了隔壁的1, 就與隔壁的1的左邊界範圍"重複"了, 會導致重複計算

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        constexpr int m = 1e9+7;
        const int n = arr.size();
        stack<int> stk1;
        vector<int> left(n);
        for(int i=0; i<n; i++)
        {
            while(!stk1.empty() && arr[stk1.top()] >= arr[i]) stk1.pop();
            left[i] = stk1.empty() ? i+1 : i - stk1.top();
            stk1.push(i);
        }

        stack<int> stk2;
        vector<int> right(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!stk2.empty() && arr[stk2.top()] > arr[i]) stk2.pop();
            right[i] = stk2.empty() ? n-i : stk2.top() - i;
            stk2.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % m;
        }

        return ans;
    }
};
