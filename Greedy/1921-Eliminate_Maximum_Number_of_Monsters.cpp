/*
題目：
https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int n = dist.size();
        vector<double> round(n); //怪獸距離戰場幾回合的時間
        for(int i=0; i<n; i++)
        {
            round[i] = static_cast<double>(dist[i]) /speed[i];
        } 

        sort(round.begin(), round.end());

        for(int i=0; i<n; i++) //開始殺怪獸,第i回合可以處理 round 大於 i 的怪獸 
        {
            if(round[i] <= i) return i;
        }

        return n;
    }
};
