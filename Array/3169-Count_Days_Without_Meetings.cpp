/*
題目：
https://leetcode.com/problems/count-days-without-meetings/description/

解說：
Sort array with start, 接著遍歷 array, 每當遇到一個區間就比較 "當前區間的 start " 是否大於 "先前區間 merge 後的 end" (至少要大於 2 才代表有空閒的時間) 
若區間差滿足, 則累加空閒時間。
因為是由 array 的頭開始, 所以最後要判斷 end 是否小於 days, 若小於則代表有額外的休閒時間。

若從 end 開始也是一樣的概念, 只是變成判斷 "當前區間 end" 是否小於 "前區間 merge 後的 start", 最後再判斷最後一個區間開始前是否有空閒時間。

*days 必定大於等於所有區間的 value

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int end = 0;
        int count = 0;

        for(auto& meeting : meetings)
        {
            int curr_end = meeting[1];
            int curr_start = meeting[0];
            if (curr_start > end + 1)
            {
                count += curr_start - end - 1;
            }
            
            end = max(end, curr_end);
        }

        if(end < days)
        {
            count += days - end;
        }

        return count;
    }
};
