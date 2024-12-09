/*
題目：
https://leetcode.com/problems/minimum-array-length-after-pair-removals/

解說：
從頭及中間開始兩兩一對測試

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int n = nums.size();
        int ans = n;
        int p1 = 0, p2 = n/2;
        while(p2 < n)
        {
            if(nums[p1] < nums[p2]) {
                ans-=2;
                ++p1;
                ++p2;
            }
            else {
                ++p2;
            }

            if(p1 >= n/2) break; //能移除的pair都已確認過了
        }

        return ans;
    }
};
