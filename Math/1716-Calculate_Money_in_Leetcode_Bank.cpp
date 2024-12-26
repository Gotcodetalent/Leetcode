/*
題目：
https://leetcode.com/problems/calculate-money-in-leetcode-bank/

解說：
sol 1. 根據題意

sol 2. 分解成數學式
week 1 : [1, 2, 3, 4, 5, 6, 7] -> 28
week 2 : [2, 3, 4, 5 ,6, 7, 8] -> 28 + 7
week 3 : [3, 4, 5, 6, 7, 8, 9] -> 28 + 7 + 7

total = ( 28*w ) + ( 0 + 7 + 14 + .... + 7w)
      = 28*w + 7*w*(w-1)/2

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int totalMoney(int n) {
        int pile = 1;
        int curr = 1;
        int deposit = 1;
        for(int i=1; i<n; i++)
        {
            if(i%7 == 0){
                curr = ++pile;
            }
            else ++curr;

            deposit += curr;
        }

        return deposit;
    }
};

class Solution {
public:
    int totalMoney(int n) {
        int week = n/7;
        int days = n - week*7; 
        int deposit = 0;

        deposit = week * 28;

        for(int i=0; i<week; i++)
        {
            deposit += i * 7;
        }

        int lastMondayMoney = week+1;
        int start = lastMondayMoney;
        for(int i=0; i<days; i++) 
        {
            deposit += start;
            ++start;
        } 

        return deposit;
    }
};
