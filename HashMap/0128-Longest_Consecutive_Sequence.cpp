/*
題目：
https://leetcode.com/problems/longest-consecutive-sequence/

解說：
使用 HashMap<key,len> 記錄遍歷到自己時的長度, 遍歷的情況有三種:
1. 只有自己
2. 有一個鄰居 (左/右)
3. 左右都有鄰居

將左右鄰居的長度記錄下來 (沒有則設為 0), 並計算當前能觸及的最大長度 -> r + l + 1
更新長度時,也更新左右鄰居的長度, 並比較最大長度

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> ump;
        int ans = 0;
        
        for(int num : nums)
        {
            if(ump.count(num)) continue;
            auto it_l = ump.find(num-1);
            auto it_r = ump.find(num+1);

            int l = it_l == ump.end() ? 0 : it_l->second;
            int r = it_r == ump.end() ? 0 : it_r->second;

            int len = r+l+1;

            ump[num] = ump[num-l] = ump[num+r] = len;

            ans = max(ans, len);
        }

        return ans;
    }
};
