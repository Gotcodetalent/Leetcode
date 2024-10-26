/*
題目：
https://leetcode.com/problems/matchsticks-to-square/description/

解說：
有n個火柴,每個火柴至少都要使用到一次,測試是否可以排成一個正方形
因此邊長target = (所有火柴長度總和) / 4
以DFS下去跑所有可能的排列, count值為0代表已找到4個邊
當挑到剛好總和是一個邊時,從頭開始挑沒有挑過的
若挑完仍不足一個邊的長度,則繼續往下挑沒挑過的
當有結果返回值為true時即找到一個解

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int n;
    bool dfs(int target, vector<int>& matchsticks, int sum, int count, int start,vector<int>& visited) {
        if(count == 0) return true;
        bool a = false, b = false;
        for(int i=start; i<n; i++)
        {
            if(visited[i] || sum +  matchsticks[i] > target) continue;
            visited[i] = true;
            if(sum + matchsticks[i] == target){
                a = dfs(target,matchsticks,0,count-1,0,visited);
            }
            else{
                b = dfs(target,matchsticks,sum + matchsticks[i],count,i+1,visited);
            }
            visited[i] = false;
            if(a || b) return true;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

    n = matchsticks.size();
    if(n < 4) return false;

    vector<int> visited(n,0);
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if(sum % 4 != 0) return false;
    int target = sum / 4;

    return dfs(target,matchsticks,0,4,0,visited); ;
    }
};
