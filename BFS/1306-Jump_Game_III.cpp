/*
題目：
https://leetcode.com/problems/jump-game-iii/

解說：
BFS的過程確認index不會超過即可得出解答

有使用到的觀念：
BFS
*/

// #include "../code_function.h"
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;

        const int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty())
        {
            int idx = q.front();
            int j1 = idx + arr[idx];
            int j2 = idx - arr[idx];
            q.pop();
            if((j1 >= 0 && j1 < n) && !visited[j1]){
                if(arr[j1] == 0) return true;
                visited[j1] = true;
                q.push(j1);
            }
            if((j2 >= 0 && j2 < n) && !visited[j2]){
                if(arr[j2] == 0) return true;
                visited[j2] = true;
                q.push(j2);
            }
        }

        return false;
    }
};
