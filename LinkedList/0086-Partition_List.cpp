/*
題目：
https://leetcode.com/problems/partition-list/description/

解說：
創造兩個dummy node & dummy pointer, 分別指向less than & greater and equal than 'x'的node
將lt的tail串向geq的head (geq_head->next), 並將geq最後一個node指向null, 最後return lt的第一個node (lt_head->next)

有使用到的觀念：

*/

// #include "../code_function.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lt_head = new ListNode();
        ListNode* geq_head = new ListNode();
        ListNode* lt = lt_head;
        ListNode* geq = geq_head;
        while(head)
        {
            if(head->val < x)
            {
                lt->next = head;
                lt = lt->next;
            }
            else {
                geq->next = head;
                geq = geq->next;
            }

            head = head->next;
        }
        lt->next = geq_head->next;
        geq->next = nullptr;

        return lt_head->next;
    }
};
