/*
題目：
https://leetcode.com/problems/longest-nice-subarray/description/

解說：
題目敘述求 longest nice subarray, nice subarray 代表內部每個元素兩兩做 bitwise & 會等於 0 的子陣列.

從 array 的起始點開始使用 sliding window 遍歷, 只要符合 nice, 
就將當前數值利用 bitwise or 加入 currBit 中, currBit 表示了所有符合標準的數的 bits 落在哪些位置. 
只要沒有符合 nice, 就使用 exclusive or (^) 從左邊界開始將之前加入數值給踢出 , 最後即可得出最大的 nice 子陣列長度.


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = INT_MIN;
        int currBit = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            while((currBit & nums[right]) != 0)
            {
                currBit ^= nums[left];
                ++left;
            }

            currBit |= nums[right];
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
