/*
題目：
https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

解說：
使任意length >= 3 的subarray內的最大元素 >= k
遍歷每個位置,求出當前所需的最小increment次數
由於最小檢查長度是3,因此在index i 的所需最小次數會是:
1. 前三個位置的最小次數 min(i-1, i-2, i-3), 加上
2. 本身所需的次數 |k-nums[i]|

最後,比較最後一個subarray中三個元素所紀錄的累積最小次數, 並返回最小值


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long a = 0, b = 0, c = 0;
        for(int num : nums)
        {
            long long tmp = min({a,b,c}) + max(0, k - num);
            a = b;
            b = c;
            c = tmp;
        }

        return min({a,b,c});
    }
};

