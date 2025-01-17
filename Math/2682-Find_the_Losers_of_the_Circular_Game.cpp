/*
題目：
https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/

解說：
Rule 
1. 遊戲開始時從第 1 個人開始傳
2. 每 round 都要傳遞給 next (round * k) step 的人
3. 有人收到 2 次球遊戲便結束 (第 1 個人剛開始那次要算進去)
4. 遊戲結束時沒收過球的為 loser


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> record(n);
        record[0] = 1;
        int round = 0, receiver = 0;
        while(1)
        {
            ++round;
            receiver = (receiver + round*k) % n;
            record[receiver]++;
            if(record[receiver] == 2) break;
        }

        vector<int> loser;
        for(int i=0; i<n; i++)
        {
            if(record[i] == 0) loser.push_back(i+1);
        }

        return loser;
    }
};
