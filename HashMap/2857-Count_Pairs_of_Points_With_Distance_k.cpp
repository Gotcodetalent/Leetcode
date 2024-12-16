/*
題目：
https://leetcode.com/problems/count-pairs-of-points-with-distance-k/

解說：
此題關鍵點為 k <= 100
因此遍歷每一種 k 的可能情形，而不是遍歷每一種 coordinates。
並且利用 x * 1000000 + y 來作為 hash map 的 key ( 1 <= xi, yi <= 100000 )


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<long long, int> ump;
        const int n = coordinates.size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            for(int j=0; j<=k; j++)
            {
                int x2 = j ^ x1;
                int y2 = (k - j) ^ y1;
                long long key = (long long)x2 * 100000 + y2;
                if(ump.find(key) != ump.end())
                {
                    cnt += ump[key];
                }
            }
            long long curr_key = (long long)x1*100000 + y1;
            ump[curr_key]++;
        }

        return cnt;
    }
};
