/*
題目：
https://leetcode.com/problems/distribute-candies-among-children-ii/

解說：
假設 n <= 3 * limit (超過則無法分配完)
先決定 fiset man 能拿到的 max & min candy數量
接著遍歷 first man 的所有情況來決定 second man 能拿到的 max & min candy數量
second man 在每個情況中的 (max - min) 即為該情況下可得到的 最多組合數 (second man 的分配完後, third man拿剩下的)
將所有組合數加總即為答案

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int firstMin = max(0, n - 2*limit);
        int firstMax = min(n, limit);
        long long ans = 0;

        for(int i=firstMin; i<=firstMax; i++)
        {
            int secondMin = max(0,n-i-limit);
            int secondMax = min(n-i,limit);
            ans += secondMax - secondMin + 1;
        }

        return ans;
    }
};
