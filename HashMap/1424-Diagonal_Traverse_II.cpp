/*
題目：
https://leetcode.com/problems/diagonal-traverse-ii/description/


解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,int> ump;
        vector<vector<int>> group;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                if(ump.count(i+j)) group[i+j].push_back(nums[i][j]);
                else{
                    group.push_back({nums[i][j]});
                    ump[i+j] = group.size() - 1;
                }
            }
        }

        vector<int> order;

        for(const auto& vec : group)
        {
            for(int i=vec.size() - 1; i>=0 ; --i)
            {
                order.push_back(vec[i]);   
            }
        }
        
        return order;
    }
};
