/*
題目：
https://leetcode.com/problems/plus-one/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n = digits.size();
        digits[n-1]++;
        for(int i=n-1; i>=1; i--)
        {
            if(digits[i] > 9)
            {
                digits[i] %= 10;
                digits[i-1]++;
            }
        }

        if(digits[0] > 9)
        {
            digits.insert(digits.begin(),1);
            digits[1] %= 10;
        }

        return digits;
    }
};
