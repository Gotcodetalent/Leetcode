/*
題目：
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

解說：
求可射破所有ballon的最小數量飛鏢,每個ballon都有一個擊中區間,區間重疊的ballon可用同一支飛標射破
算出merge後區間重疊的部分,若超過重疊區則產生一個新區間,即多一支標
先以end由小到大排序,再以start是否小於當前重疊區間的end,來判斷區間是否可重疊
- if yes,則更新重疊區的大小
- if no,則將重疊區設定為新區間

有使用到的觀念：

*/

// #include "../code_function.h"
bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;

        sort(points.begin(), points.end(),cmp);
        int arrows = 1, end = points[0][1];
        vector<int> prev = points[0];

        for(vector<int> i: points)
        {

            if(i[0] <= prev[1])
            {
                prev = {i[0],prev[1]}; 
            }
            else{
                arrows++;
                prev = i;
            }
        } 

        return arrows;
    }
};
