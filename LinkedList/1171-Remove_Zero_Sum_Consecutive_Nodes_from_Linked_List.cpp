/*
題目：
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

解說：
如果在某2個節點有相同的prefix sum, 代表2個節點中間有sum == 0的情況產生
使用ump記錄每個prefix sum對應的節點位置, 如果有sum == 0的情況, 那麼該 prefix sum 在 ump 會對應到sum == 0的sublist的最後一個node
ex: 1, 2, -2, 3, 5, 則prefix sum為1的node 原本是node 1, 變為node 3
只要遍歷一次並把 sum == 0 的 sublist跳過即可 

有使用到的觀念：

*/

// #include "../code_function.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return nullptr;

        ListNode* dummy = new ListNode(1001,head);
        unordered_map<int, ListNode*> ump;

        int prefixSum = 0;

        for(ListNode* curr = dummy; curr != nullptr; curr = curr->next)
        {
            prefixSum += curr->val;
            ump[prefixSum] = curr;
        }

        prefixSum = 0;

        for(ListNode* curr = dummy; curr != nullptr; curr=curr->next)
        {
            prefixSum += curr->val;
            curr->next = ump[prefixSum]->next;
        } 

        return dummy->next;;
    }
};
