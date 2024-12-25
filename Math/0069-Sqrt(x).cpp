/*
題目：
https://leetcode.com/problems/sqrtx/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, up = x, mid;
        if(x < 2) return x;

        while(low < up)
        {
            mid = low + (up - low)/2;

            if(mid*mid <= x && (mid+1)*(mid+1) > x) return mid;
            else if(mid*mid < x) low = mid + 1;
            else up = mid; 
        }

        return low-1;
    }
};
