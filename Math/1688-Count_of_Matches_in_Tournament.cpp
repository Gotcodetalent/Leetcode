/*
題目：
https://leetcode.com/problems/count-of-matches-in-tournament/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numberOfMatches(int n) {
        int match = 0;
        while(n>1){
            match += n/2;
            if(n%2 == 1){
                n = n/2 + 1;
            }
            else n/=2; 
        }

        return match;
    }
};
