/*
題目：
https://leetcode.com/problems/task-scheduler/description/

解說：
找出完成所有任務需要的最少round, 且規定相同task之間需要至少隔 n 個 intervals
找出最大頻率的task, 計算滿足隔間需求所需要的round數
答案有兩種可能:
1. 滿足interval需求下的值 : 將最高頻率的任務間插入n個 inteval, 多餘的空間可以放好所有task
  i. 最高頻率task 只有1種
  ii. 最高頻率 task 超過一種
2. task總數 : task種類超出了interval n, 只要依序將task排列即可

ex: n = 4, {A*5, B*5, C*4, D*3} , # -> idle
ABCD#
ABCD#
ABCD#
ABC##
AB


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }

        int maxFreq = 0;
        for (const auto& pair : taskCount) {
            maxFreq = max(maxFreq, pair.second);
        }

        int maxFreqTaskCount = 0;
        for (const auto& pair : taskCount) {
            if (pair.second == maxFreq) {
                maxFreqTaskCount++;
            }
        }

        int idleTime = (maxFreq - 1) * (n + 1) + maxFreqTaskCount;
        return max(idleTime, (int)tasks.size()); //如果計算出的總冷卻架構時間小於任務總數量，說明我們不能在冷卻架構中安排所有任務，因此最少需要執行的時間就是任務的總數量。
    }
};
