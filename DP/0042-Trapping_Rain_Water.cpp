/*
題目：
https://leetcode.com/problems/trapping-rain-water/

解說：
將每個bar能形成的水漥獨立來看,能夠形成水漥,必定左側跟右側要大於bar本身高度
所以只要紀錄對於每個bar的左側最高、右側最高, 再將兩者取min, 最後扣除bar本身高度, 就可以得出這個bar可以產生多大的水漥

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size(); 
        vector<int> l(n), r(n);
        l[0] = height[0], r[n-1] = height[n-1];
        for(int i=1; i<n; i++) l[i] = max(l[i-1],height[i]); //紀錄每個bar左側最高
        for(int i=n-2; i>=0; i--) r[i] = max(r[i+1],height[i]); //紀錄每個bar右側最高

        int sum = 0;
        for(int i=0; i<n; i++) sum += min(l[i],r[i]) - height[i];

        return sum;
    }
};
