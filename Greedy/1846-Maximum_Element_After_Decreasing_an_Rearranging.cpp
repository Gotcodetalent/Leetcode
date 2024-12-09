/*
題目：
https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

解說：
滿足2條件:
1.第一個元素為 1
2.相鄰element差異最大為1

可執行的operation:
1. 無限減法
2. 挪移元素

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        arr[0] = 1;
        int mx = arr[0];
        for(int i=1; i<n; i++)
        {
            if(abs(arr[i]-arr[i-1]) > 1) arr[i] = arr[i-1] + 1;
            mx = max(mx, arr[i]);
        }

        return mx;
    }
};
