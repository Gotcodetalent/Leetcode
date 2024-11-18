/*
題目：
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

解說：
sol 1. 先算出共有幾個node, 使用dummy pointer指向head, 找到順序為count - n的node (curr->next)並刪除
sol 2. two pointer, 先將兩個pointer距離設定為n, 接著讓兩個pointer前進,直到第一個pointer走到底, 此時第二個pointer的位置即為reverse order的第n個node 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;
        
        while(curr != nullptr) 
        {
            ++count;
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0,head);
        curr = dummy;
        for(int i=0; i<count - n; i++) curr = curr->next;

        ListNode* del = curr->next;
        curr->next = (curr->next)->next;
        delete del;

        return dummy->next;
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* dummy = new ListNode(0,head);
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        for(int i=0; i<n; i++) p1 = p1->next;
        while(p1->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* del = p2->next;
        p2->next = (p2->next)->next;
        delete del;

        return dummy->next;
    }
};
