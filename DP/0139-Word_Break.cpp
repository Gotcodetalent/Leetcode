/*
題目：
https://leetcode.com/problems/word-break/

解說：
Sol 1:
dp[i]代表是否能從dict中拼湊出s[0...i-1]的子字串

Sol 2:
使用 recursion 的概念，若已經在 Dict 內則不用求解

有使用到的觀念：
DP

*/

// #include "../code_function.h"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] && wordDictSet.count(s.substr(j, i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }

    bool wordBreak(const string& s, const unordered_set<string>& dict){
        if(dp.count(s)) return dp[s];
        if(dict.count(s)) return dp[s] = true;

        for(int j = 1; j < s.length(); j++){
            string left = s.substr(0, j);
            string right = s.substr(j);

            if(dict.count(right) && wordBreak(left, dict))
                return dp[s] = true;
        }
        return dp[s] = false;
    }
private:
    unordered_map<string, bool> dp;
};
