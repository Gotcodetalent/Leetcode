/*
題目：
https://leetcode.com/problems/minimum-time-visiting-all-points/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1; i<points.size(); i++)
        {
            ans += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }

        return ans;
    }
};
