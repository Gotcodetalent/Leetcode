/*
題目：
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

解說：
因為 s 由 lower case 構成、 長度為 3 的 palindrome 左右兩側是相同的
所以只要遍歷 a~z, 找出左右兩側為 a~z 時,在 s 中可以組成的 palindrome 種類
計算的步驟如下:
1.找出當前遍歷的字母的第一個位置(start) & 最後一個位置(end)
2.使用 set 計算出 start 至 end 中間共出現幾種字母, 出現幾種即代表可形成幾個 subsequence

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> ump;
        int cnt = 0;
        for(int i=0; i<26; i++)
        {
            char curr = 'a' + i;
            int start = -1, end = -1;
            for(int j=0; j<s.length(); j++)
            {
                if(s[j] == curr) {
                    start = j;
                    for(int k=j+1; k<s.length(); k++)
                    {
                        if(s[k] == curr) end = k;
                    }
                    break;
                }
            }
            unordered_set<char> middle;
            for(int l=start+1; l<end; l++) middle.insert(s[l]);
            cnt += middle.size();
        }


        return cnt;
    }
};
