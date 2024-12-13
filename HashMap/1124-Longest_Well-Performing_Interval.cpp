/*
題目：
https://leetcode.com/problems/longest-well-performing-interval/description/

解說：
概念類似0525
如果 sum > 0 可以一直更新最大區間; 若 sum <= 0, 且存在 ump[sum - 1], 代表有一段可用的區間


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> ump;
        ump[0] = -1;
        int mx = 0;
        int sum = 0;
        for(int i=0; i<hours.size(); i++)
        {
            sum += (hours[i] > 8) ? 1 : -1;
            if(sum > 0) mx = max(mx, i+1);
            else {
                if(ump.count(sum - 1)) mx = max(mx, i - ump[sum - 1]);
            }

            if(!ump.count(sum)) ump[sum] = i;
        }

        return mx;
    }
};
