/*
題目：
https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

解說：
求出要執行幾次operation才能使陣列中所有元素相等
先記錄所有陣列中的值出現的頻率,接著依照給定input數值的範圍 (1~50000)從尾端依序累加需要運算的次數
紀錄的頻率中第n大的數在運算完後,會變成第n-1大的數,因此每回合在運算時,會將比自己大的數值個數累加進去

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int n = nums.size();
        vector<int> count(50001,0);
        int min = 0, operation = 0, temp = 0;
        for(int i=0; i<n; i++) {
            count[nums[i]]++;
        }
        for(int i=50000; i>=0; i--) {
            if(count[i] > 0) {
                temp = count[i] + temp;
                operation += temp;
            }
        }
        operation -= temp;
        return operation;
    }
};
