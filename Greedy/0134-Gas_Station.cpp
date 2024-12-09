/*
題目：
https://leetcode.com/problems/gas-station/description/

解說：
將 gas[i] - cost[i] 視為 某個 xk
則可以將問題看作x1 + x2 + x3 + .... + xn >= 0 是否有解, 且滿足從x1累加到xn的過程中不會產生負數
由於x1可以由任意的gas[i] - cost[i]表示, 當我們確定有解 (total >= 0)時, 只要從頭遍歷,找到過程中不會產生負數的起點即可

ex: a+b+c+d+e >= 0, a=1, b=2, c=3, d=-10, e=5
則只要把e挪到a的順序即可, e+a+b+c+d >= 0

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int total = 0, curr = 0;
        int start = 0;
        for(int i=0; i<n; i++)
        {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if(curr < 0)
            {
                start = i+1;
                curr = 0;
            }
        }

        return total >= 0 ? start : -1;
    }
};
