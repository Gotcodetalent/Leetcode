/*
題目：
https://leetcode.com/problems/jump-game-ii/description/
0055進階版, 求出min number of step

解說：
從index 0開始linear scan, 使用current_reach變數紀錄目前最遠能跳到哪裡, 並在index到達current_reach前不斷更新下一跳能到的最遠距離, 並記錄在reach內。
greedy的從每一步尋找最大跳躍距離, 最後得到global optimal。

有使用到的觀念：
DP, Greedy

*/

// #include "../code_function.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        int current_reach = 0, reach = 0, jp = 0;
        for(int i=0; i<n; i++)
        {
            reach = max(reach, i + nums[i]);
            if(i == current_reach)
            {
                jp++;
                current_reach = reach;
            }
        }

        return jp;
    }
};
