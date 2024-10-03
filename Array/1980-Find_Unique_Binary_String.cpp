/*
題目：
https://leetcode.com/problems/find-unique-binary-string/description/

解說：
找出給定字串陣列中沒有出現過的任意一個排列

有使用到的觀念：
DFS
*/

// #include "../code_function.h"
class Solution {
public:
    unordered_map<string,int> unique;
    string ret="";
    bool found = false;
    void dfs(int n, string s) {
        if(found) return;
        if(n == 0) {
            if(unique.find(s) == unique.end()) {
                ret = s;
                found = true;
            }
            return;
        }
        dfs(n-1, s+"0");
        dfs(n-1, s+"1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums[0].size();
        for (const auto& num : nums) {
            unique.emplace(num, 1);
        }
        string s ="";
        dfs(n, s);
        return ret;
    }
};
