/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

解說：
給定一個陣列, in-place的去找出一個k值, 此k值能夠代表陣列的所有元素 (陣列中有重複的元素的話, 至多只能出現2次)

有使用到的觀念：
Two Pointers
*/

// #include "../code_function.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if(n < 3) return n;

        int ans = 2;
        for(int i=2; i<n; i++)
        {
            if(nums[i] == nums[ans - 1] && nums[i] == nums[ans - 2]) continue;
            else {
                nums[ans] = nums[i];
                ans++;
            }
        }
        return ans;
    }
};
