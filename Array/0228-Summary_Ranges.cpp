/*
題目：
https://leetcode.com/problems/summary-ranges/

解說：
要找出所有連續整數的區間(前後相差1),若無連續,則以單一整數代表一個區間
首先以start,end來找出區間頭尾,當出現斷層時就輸出到ret中,並把頭尾設為斷層處的整數
最後一個結果需要額外在迴圈結束時輸出出來


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> ret;
        if (nums.empty()) return ret;
        int start = nums[0], end = nums[0];
        string result = "";
        for(int i=1; i<n; i++)
        {
            if(nums[i] == end + 1){
                end = nums[i];
                result = to_string(start) + "->" + to_string(end);
            }
            else
            {
                if(start == end)
                {
                    result = to_string(start);
                }
                else
                {
                    result = to_string(start) + "->" + to_string(end);
                }
                start = end = nums[i];
                ret.push_back(result);
            }
        }

        if (start == end) {
            ret.push_back(to_string(start));
        } else {
            ret.push_back(to_string(start) + "->" + to_string(end));
        }

        return ret;
    }
};
