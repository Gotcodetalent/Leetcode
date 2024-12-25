/*
題目：
https://leetcode.com/problems/single-number-ii/

解說：
因為重複的數會出現3次, 當轉換成2進制時, 每個重複的數的每個bit加總後 mod 3 會是 0, 所以加總每個數的bit 再 mod 3後, 剩下的便是single number的bit值

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for(int num : nums)
        {
            for(int i=0; i<32; i++)
            {
                bits[i] += (num >> i)&1;
            }
        }

        int ans = 0;
        for(int i=0; i<32; i++)
        {
            ans += (bits[i]%3) << i;
        }

        return ans;
    }
};
