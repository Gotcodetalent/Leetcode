/*
題目：
https://leetcode.com/problems/longest-increasing-subsequence/

解說：
Sol 1.
找出每個長度下的LIS, d[i]代表nums長度為i+1時的LIS長度

Sol 2.
patience sorting, 對於每個元素, 找出當前長度下,能形成的最大子陣列, 並將其擺放在該位置上
當有新的元素要加入時, 先與LIS的最大元素比較(dp末端元素),若大於該元素,代表可形成更長的LIS, 則插入末端
反之, 則找尋可以覆蓋的位置, 供之後加入的元素比較 (即使覆蓋掉也不影響結果, 除非後續能持續覆蓋到產生更長的LIS)

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        int currMax = 1;
        vector<int> dp(n,1); 
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }

            currMax = max(dp[i],currMax);
        }

        return currMax;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp; 
        for(int i=0; i<n; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]); //返回不小於nums[i]的第一個element的位置
            if(it == dp.end()) dp.push_back(nums[i]);
            else *it = nums[i];

        }

        return dp.size();
    }
};
