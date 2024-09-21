/*
題目：
https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

解說：
排序後從n/3開始兩兩取一組,小的那個數就是自己的收益

有使用到的觀念：
greedy

*/

// #include "../code_function.h"
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const int n = piles.size();
        const int start = n/3;
        sort(piles.begin(),piles.end());
        int ret = 0;
        for(int i=start; i<n; i+=2) ret+=piles[i];
        return ret;
    }
};
