/*
題目：
https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/

解說：
給定一個 2d array, 以及 integer x, 若可以藉由 +/- x 將 array 中所有元素變成同一個 value, 則計算最小 operation 次數, 反之則返回 error

Step 1. 化成 1d array 並 sort
Step 2. 找到中位數所在位置 mid （最小值必定是與中位數之間的差異）
Step 3. 確認每個數都能夠藉由 +/- x 來達到中位數值, 若有一個數無法滿足則返回 error (-1)


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int n = grid.size();
        const int m = grid[0].size();
        vector<int> arr;
        for(int i = 0; i < n*m; ++i) 
        {
            arr.push_back(grid[i/m][i%m]);
        }
        sort(arr.begin(), arr.end());

        int mid = (n*m - 1)/2;
        int count = 0;

        for(auto& e : arr)
        {
            if ((e - arr[mid])%x == 0)
            {
                count += abs(e - arr[mid])/x;
            }
            else
            {
                count = -1;
                break;
            }
        }

        return count;
    }
};
