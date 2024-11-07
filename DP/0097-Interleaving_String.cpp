/*
題目：
https://leetcode.com/problems/interleaving-string/

解說：
dp(i, j)代表, s1的前i個字元及s2的前j個字元,是否能組成s3的前i+j個字元
dp的index與字串s的index定義不同須注意

有使用到的觀念：
DP

*/

// #include "../code_function.h"
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int n = s1.size();
        const int m = s2.size();
        const int l = s3.size();

        if(l != n+m) return false;

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true; 
        for(int i=1; i<=n; i++) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int j=1; j<=m; j++) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1]; 
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[n][m];
    }
};
