/*
題目：
https://leetcode.com/problems/candy/

解說：
左邊掃過來, 先確保與左邊鄰居為合法的情況下至少要幾顆
再從右邊掃過來, 確保與右邊鄰居也是合法的

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> candy(n,1);
        for(int i=1; i<n; i++)
        {
            if(ratings[i]>ratings[i-1]) candy[i] = candy[i-1] + 1;
        }
        
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1] && candy[i] <= candy[i+1]) candy[i] = candy[i+1] + 1;
        }

        int sum = 0;
        for(int c: candy)
        {
            sum+=c;
        }

        return sum;
    }
};
