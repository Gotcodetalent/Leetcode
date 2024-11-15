/*
題目：
https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

解說：
使用一個 vector 紀錄每一個seat的位置，計算相鄰兩個seat之間的間隔即可知道前一組能產生幾種組合 (ex: 若相鄰的組間有三個花盆, 則前一組可以選0,1,2,3個花盆為一組, 即i+4 - i種)
因題目要兩個seat為一組，因此 i 從 index 2 開始, i+=2

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numberOfWays(string corridor) {
        constexpr long long M = 1e9+7;
        const int n = corridor.length();
        vector<int> seat;
        for(int i=0; i<n; i++)
        {
            if(corridor[i] == 'S') seat.push_back(i);
        }

        if(seat.size() == 0 || seat.size()%2 != 0) return 0;

        long long ans = 1;
        for(int i=2; i<seat.size(); i+=2)
        {
            long long diff = seat[i] - seat[i-1];
            ans *= diff;
            ans %= M; 
        }

        return ans;
    }
};
