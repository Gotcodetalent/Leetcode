/*
題目：
https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/

解說：
01 -> 10 相當於將1往左挪移,將0往右挪移
需要計算兩個部分:
1. 最後一個1至少要跨越幾個0, 即0出現的次數 (1次opration可以往左移,但有可能被前面的阻擋, ex: 1011010 i=3的'1'被i=2的'1'給擋住)
2. 計算最左邊的0總共阻擋了幾次1

取1、2之maximum

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        const int n = s.length();
        int count = 0, ans = 0;
        for(char ch : s)
        {
            if(ch == '0') count++;
            else{
                if(count > 0) ans = max(ans + 1, count);
            }
        }

        return ans;
    }
};
