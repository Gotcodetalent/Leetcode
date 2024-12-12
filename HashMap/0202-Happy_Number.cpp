/*
題目：
https://leetcode.com/problems/happy-number/


解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> num;
        while(n > 0)
        {
            if(num.count(n)) break;
            num[n] = 1;
            int tmp = 0, copy = n;            
            while(copy > 0)
            {
                int r =  copy % 10;
                tmp += r * r;
                copy /= 10;
            }
            if(tmp == 1) return true;
            n = tmp;
        }

        return false;
    }
};
