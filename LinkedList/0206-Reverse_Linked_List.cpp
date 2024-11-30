/*
題目：
https://leetcode.com/problems/reverse-linked-list/description/

解說：
pre, head, next依序迭代到head為nullptr

有使用到的觀念：

*/

// #include "../code_function.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *preNode = NULL;
        while(head)
        {
            nextNode = head->next;
            head->next = preNode;
            preNode = head;
            head = nextNode;
        }

        return preNode;
    }
};
