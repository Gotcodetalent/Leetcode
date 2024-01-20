/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

解說：
給定一個陣列, in-place的去找出一個k值, 此陣列的前k個元素能夠代表陣列的所有元素 (陣列中有重複的元素的話, 至多只能出現2次)

在陣列Size > 3時才需要進行比較來找出答案, 假設首個元素為x0,次個為x1, 依此類推, 我們假設目前的解(ans)指在陣列第三個位置(k=3), 則我們可使用線性搜索來確認接下來的每個元素x(i)
是否與前兩個元素皆相等, 只要有不完全相同的情況產生, 代表我們需要再多使用一格來代表陣列所有元素, 也就是ans值必須+1, ex: x(i-1)=4, x(i-2)=3, 則x(i)=4 or x(i)=5皆是可行解。
則可以將x(i)放置於目前ans所指的位置。


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
