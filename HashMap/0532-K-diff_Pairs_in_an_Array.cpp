/*
題目：
https://leetcode.com/problems/k-diff-pairs-in-an-array/

解說：
情況分為兩種 :
1. k == 0
2. k > 0

紀錄各個數字出現的次數, 
k == 0 時, 只要出現次數大於1次的數字就能組成 pair
k > 0 時, 單向查找距離自己 k 的數字是否存在即可


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int pairs = 0;
        for(int num : nums) ump[num]++;
        for(auto& p : ump)
        {
            if(k == 0)
            {
                if(p.second > 1) ++pairs;
            }
            else{
                if(ump.count(p.first + k))
                {
                    ++pairs;
                }
            }
        }

        return pairs;
    }
};
