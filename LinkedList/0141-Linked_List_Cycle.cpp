/*
題目：
https://leetcode.com/problems/linked-list-cycle/

解說：
快慢指標, 只要slow與fast能夠相遇, 就代表有cycle

有使用到的觀念：

*/

// #include "../code_function.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};
