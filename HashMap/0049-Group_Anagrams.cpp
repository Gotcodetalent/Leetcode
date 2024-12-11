/*
題目：
https://leetcode.com/problems/group-anagrams/

解說：
同個"排序後的原字串"產生的排列組合, 排序後會相同, 因此可以原字串作為 key 在 HashMap 進行紀錄, value 則為 group index

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> ump;
        const int n = strs.size();
        for(string str : strs)
        {
            string key = str;
            sort(key.begin(),key.end()); //找出原字串
            if(ump.count(key)) ans[ump[key]].push_back(str);
            else {
                vector<string> group = {str};
                ans.push_back(group);
                ump[key] = ans.size() - 1; //set group index
            }
        }

        return ans;
    }
};
