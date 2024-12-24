/*
題目：
https://leetcode.com/problems/remove-adjacent-almost-equal-characters/

解說：
找出讓 word 不會產生 "相鄰字母相同 or 相鄰字母在字母順序上是連續的" 情況, 所需要的最小步驟
當我們調整了一個位置 pos 的字母時, pos + 1 的左側便不必再檢查 (line 24: i++) 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int cnt = 0;
        for(int i=1; i<word.length(); i++)
        {
            if(abs(word[i] - word[i-1]) <= 1)
            {
                ++cnt;
                i++;
            }
        }

        return cnt;
    }
};
