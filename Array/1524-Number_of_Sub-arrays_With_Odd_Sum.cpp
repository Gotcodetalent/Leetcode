/*
題目：
https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

解說：
類似DP, 逐個紀錄 sum 為 odd/even 的 sub-array個數
並由 prefix sum (current_sum) 判斷遍歷到當前位置時可以新增多少符合條件的子陣列

（圖解）
情況 1.current_sum 為 even
｜-------even-------| -> if |--odd---|-----(X)-----|, then X must be odd.
情況 2.current_sum 為 odd
｜-------odd--------| -> if |--even--|-----(X)-----|, then X must be odd.

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int m = 1e9 + 7;
        const int n = arr.size();
        long long ans = 0;
        int current_sum = 0, even_cnt = 1, odd_cnt = 0;

        for(int i = 0; i < n; ++i)
        {
            current_sum += arr[i];
            if(current_sum%2 == 0)
            {
                ans = (ans + odd_cnt) % m;
                even_cnt++;
            }
            else{
                ans = (ans + even_cnt) % m;
                odd_cnt++;
            }
        }

        return ans;
    }
};
