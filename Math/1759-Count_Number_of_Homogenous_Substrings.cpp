/*
題目：
https://leetcode.com/problems/count-number-of-homogenous-substrings/

解說：
對於具有連續相同字母的子字串,ex: aaa,bb, cccc, 產生的homogenous-substring數量為 1 + 2 + ... + length
因此只要掃描一次字串,紀錄當前連續的字母 && 連續的長度, 將連續長度加總 (Line 19: curr_len) 即可
如 s = "aaab", 當 scan 到 
s[0] : curr_len 為 1, 加總 1
s[1] : curr_len 為 2 ,加總 2  
s[2] : curr_len 為 3, 加總 3
s[3] : 因為與 curr_idx 指向的字母不同, 故更新 curr_idx, 並將curr_len 變為 1, 最後加總 1 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countHomogenous(string s) {
        constexpr int m = 1e9+7;
        int curr_idx = 0;
        int curr_len = 0;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == s[curr_idx])
            {
                ++curr_len;
                ans = (ans + curr_len)%m;
            }
            else{
                curr_len = 1;
                curr_idx = i;
                ans = (ans + 1)%m;
            }
        }

        return ans;
    }
};
