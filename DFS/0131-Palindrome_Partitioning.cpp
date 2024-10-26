/*
題目：
https://leetcode.com/problems/palindrome-partitioning/

解說：
ans的subset中,palindromes滿足x1 + x2 + x3 ... + xk = n, 其中 1 <= x1, x2, ..., xk , n為字串s的長度, 1<= k <= n. 
因此只要從s的第一個char開始一次選1個,2個,...,選完後開始下個遞迴,從上次選取的index + 1開始繼續選,直到選滿長度n

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<vector<string>> ans;
    bool check(string s)
    {
        int n = s.length();
        for(int i=0; i<n/2; i++)
        {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    void dfs(string s, int start, vector<string> vec) {
        int n = s.length();
        if(start == n) {
            ans.push_back(vec);
            return;
        }
        for(int i=start; i<n; i++)
        {
            string sub = s.substr(start,i-start+1);
            if(check(sub)) {
                vec.push_back(sub);
                dfs(s, i+1, vec);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        dfs(s,0,vec);
        return ans;
    }
};
