/*
題目：
https://leetcode.com/problems/combination-sum/

解說：
從給定的陣列重複挑出多個數相加,使得總和為target
先排序後再跑dfs(確保不會有重複的組合產生),只要不超過當前target便可以拿取,並同時記錄拿取的index值確保下一輪dfs可以重複拿取該元素

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int start, vector<int>& vec){
        if(target == 0){
            ans.push_back(vec);
            return;
        }
        else{
            for(int i=start; i<n; i++)
            {
                if(candidates[i] > target) continue;
                vec.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i, vec);
                vec.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n = candidates.size();
        vector<int> vec;
        dfs(candidates,target,0,vec);
        return ans;
    }
};
