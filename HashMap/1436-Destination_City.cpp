/*
題目：
https://leetcode.com/problems/destination-city/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> ump;
        for(const auto& path : paths)
        {
            ump[path[0]]++;
        }

        for(const auto& path : paths)
        {
            if(!ump.count(path[1])) return path[1];
        }

        return "";
    }
};
