/*
題目：
https://leetcode.com/problems/insert-interval/description/

解說：
分成3個case插入

case 1: 比較newInterval的頭跟想合併的區間的尾, 如果大於區間的尾, 代表不能合併, 則直接push進vec
case 2: 有可以merge的情況產生, 則merge完後確認接下來的區間是否可以繼續merge, 並更新新區間的頭尾
case 3: case 2的loop結束, 但i < n, 代表還沒將interval中的元素遍歷, 則將剩餘的push進入

**原本的list是已經排序過的!!!

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>> ret;
        //vector已是排序好的狀態
        //case 1: 新插入的頭大於前面的屁股, 因此沒有需要merge的情況產生, 所以持續push進ret裡
        while(i < n && intervals[i][1] < newInterval[0])
        {
            ret.push_back(intervals[i]);
            i++;
        }
        //case 2: 有可以merge的情況產生, 逐個比較是否能繼續merge
        while(i < n && newInterval[1] >= intervals[i][0]) //新區間的屁股大於interval[i]的頭代表可以merge
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ret.push_back(newInterval);

        //case 3: 產生merge後, 但還沒搜索完 --> 又有新插入的頭大於前者屁股的情況 --> 產生新區間
        while(i < n)
        {
            ret.push_back(intervals[i]);
            i++;
        }

        return ret;
    }
};
