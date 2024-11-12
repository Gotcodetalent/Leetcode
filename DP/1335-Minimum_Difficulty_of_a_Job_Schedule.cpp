/*
題目：
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

解說：
dp[i][k] 表示將前 i 個工作分配到 k 天內的最小難度和。

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();
        
        // 在jobDifficulty的開頭插入0，以便1到n的索引對應於實際工作
        jobDifficulty.insert(jobDifficulty.begin(), 0);

        // 初始化動態規劃DP矩陣，大小為(n+1) x (d+1)，初始值為INT_MAX/2，避免overflow
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));

        // 初始化dp矩陣的基礎情況，dp[0][0]表示0個工作分配到0天的難度和為0
        dp[0][0] = 0;

        // 遍歷所有工作
        for (int i = 1; i <= n; i++) {
            // 從第1天到第d天遍歷所有可能的天數，且保證天數不超過工作數
            for (int k = 1; k <= min(d, i); k++) {
                // 初始化當前日的最大工作難度
                int mx = jobDifficulty[i];
                // 逆向遍歷從第i個工作到第k個工作
                for (int j = i; j >= k; j--) {
                    // 更新當前天的最大工作難度
                    mx = max(mx, jobDifficulty[j]);
                    // 更新dp矩陣，計算將i個工作分配到k天的最小難度和
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + mx);
                }
            }
        }

        // 如果最終結果仍然是初始值，說明無法在d天內分配所有工作，返回-1
        if (dp[n][d] >= INT_MAX / 2) return -1;
        // 返回最小難度和
        return dp[n][d];
    }
};
