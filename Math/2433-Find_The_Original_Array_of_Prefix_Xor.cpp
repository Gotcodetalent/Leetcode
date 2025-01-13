/*
題目：
https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int curr_Xor = 0;
        vector<int> ans;
        for(int i=0; i<pref.size(); i++)
        {
            int original = curr_Xor ^ pref[i];
            ans.push_back(original);
            curr_Xor ^= original;
        }

        return ans;
    }
};
