/*
題目：
https://leetcode.com/problems/merge-intervals/

解說：
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

將給定的vector(intervals)中的區間收斂成最精簡的形式
首先將intervals進行sorting
接著逐一進行比較, 並放入新的容器vec中, 會用到start, end兩個指標指向下個要被push進vector的元素之頭尾

因為sort過, 所以我們只需要考慮線性搜索時, 每一個元素的首項是否 > 目前的end值, ex: [1,3], [2,6], 2小於3所以要比較尾部元素6、3, 此時start為1, end為6
若大於end值, 則代表要輸入一個新的區間; 若小於等於end值, 則進行尾部元素的比較後更新end值

有使用到的觀念：
Two Pointer, Array

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return intervals;
    }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> vec;
        int i, size, start, end;
        size = intervals.size()-1;
        for(i=0; i<=size; i++){
            if(intervals[i][0] > end || vec.empty()){
                start = intervals[i][0];
                end = intervals[i][1];
                vec.push_back({start,end});
            }
            else{
                vec.back()[1] = end = max(end,intervals[i][1]);
            }
        }
        
        return vec;
        }
};

// 另一種寫法
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(const auto& v : intervals)
        {
            if(ans.empty() || v[0] > ans.back()[1]) ans.push_back(v);
            else
            {
                ans.back()[1] = max(v[1], ans.back()[1]);
            }
        }

        return ans;
    }
};
