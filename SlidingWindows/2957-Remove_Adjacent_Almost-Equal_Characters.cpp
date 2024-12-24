/*
題目：
https://leetcode.com/problems/remove-adjacent-almost-equal-characters/

解說：
找出讓 word 不會產生 "相鄰字母相同 or 相鄰字母在字母順序上是連續的" 情況, 所需要的最小步驟
以從左邊開始為例, 當我們調整了一個位置 pos 的字母時, pos + 1 的左側便不必再檢查 (line 24: i++) 
從左右各掃一次看哪一邊需要的步驟最少

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int lcnt = 0;
        for(int i=1; i<word.length(); i++)
        {
            if(abs(word[i] - word[i-1]) <= 1)
            {
                ++lcnt;
                i++;
            }
        }

        int rcnt = 0;
        for(int i=word.length()-2; i>=0 ; i--)
        {
            if(abs(word[i] - word[i+1]) <= 1)
            {
                ++rcnt;
                i--;
            }
        }

        return min(rcnt, lcnt);
    }
};
