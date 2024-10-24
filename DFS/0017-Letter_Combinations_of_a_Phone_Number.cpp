/*
題目：
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

解說：
建立hash table,dfs找尋所有排列組合

有使用到的觀念：
DFS
*/

// #include "../code_function.h"
class Solution {
public:
    unordered_map<char, vector<char>> ump;
    vector<string> ans;
    int n = 0;
    void dfs(string digits, int curr, string tmp){
        if(curr == n)
        {
            ans.push_back(tmp);
            return;
        }
        for(auto& ch : ump[digits[curr]])
        {
            dfs(digits,curr + 1, tmp+ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if(n == 0) return {};
        ump['2'] = {'a','b','c'};
        ump['3'] = {'d','e','f'};
        ump['4'] = {'g','h','i'};
        ump['5'] = {'j','k','l'};
        ump['6'] = {'m','n','o'};
        ump['7'] = {'p','q','r','s'};
        ump['8'] = {'t','u','v'};
        ump['9'] = {'w','x','y','z'};
        
        dfs(digits,0,"");

        return ans;
    }
};
