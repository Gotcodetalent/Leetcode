/*
題目：
https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> map;
        int ret = 0, count = 0;
        for(int i: arr) 
        {
            map[i]++;
            if (map[i] > count) 
            {
                count = map[i];
                ret = i;
            }
        }
        return ret;
    }
};
