/*
題目：
https://leetcode.com/problems/find-common-elements-between-two-arrays/

解說：
先scan一次nums1並記錄count值,接著scan nums2,若元素 x 對應到的count值大於0,代表nums1中有4個值存在於nums2
便將這些值累加到a中,並設定cnt值為-1,代表已經累加過,後續nums2中有相同元素出現時只需累加到b

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(101,0);
        int a = 0;
        int b = 0;
        for(auto& num: nums1) cnt[num]++;
        for(auto& num: nums2) 
        {
            if(cnt[num] > 0)
            {
                a += cnt[num];
                cnt[num] = -1;
                b++;
            }
            else if(cnt[num] == -1) b++;
        }

        
        return {a,b};
    }
};
