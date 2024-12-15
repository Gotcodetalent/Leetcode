/*
題目：
https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

解說：
先記錄所有node之間的關係, 接著找到只與一個node連接的點, 從這個node開始串起array
因為每個非起點 or 終點的 node 會與2個點連接, 確認2點之中哪個不是上一個點, 就可以選擇此點並繼續串聯下去

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    unordered_map<int, vector<int>> ump;
    vector<int> ans;
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(const auto& vec : adjacentPairs)
        {
            ump[vec[0]].push_back(vec[1]);
            ump[vec[1]].push_back(vec[0]);
        }

        for(const auto& p : ump)
        {
            if(p.second.size() == 1)
            {
                ans.push_back(p.first);
                search(p.first, p.second[0]);
                break;
            }
        }

        return ans;
    }

    void search(int prev, int curr)
    {
        ans.push_back(curr);
        if(ump[curr].size() == 1) return;
        int tmp = ump[curr][0] == prev ? ump[curr][1]: ump[curr][0];
        search(curr, tmp);
    }
};
