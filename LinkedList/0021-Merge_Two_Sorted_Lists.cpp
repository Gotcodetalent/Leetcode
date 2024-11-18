/*
題目：
https://leetcode.com/problems/merge-two-sorted-lists/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"

C++:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(list1 != nullptr && list2 != nullptr)
        {
            ListNode* tmp = new ListNode(0);
            if(list1->val > list2->val)
            {
                tmp->val = list2->val;
                list2 = list2->next;
            }
            else{
                tmp->val = list1->val;
                list1 = list1->next;
            }
            curr->next = tmp;
            curr = curr->next;
        }
        if(list1 == nullptr) curr->next = list2;
        if(list2 == nullptr) curr->next = list1;
        
        return dummy->next;
    }
};

C:
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    dummy->next = NULL;
    struct ListNode* curr = dummy;
    while(list1 != NULL && list2 != NULL)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(list1->val < list2->val)
        {
            tmp->val = list1->val;
            list1 = list1->next;
        }
        else {
            tmp->val = list2->val;
            list2 = list2->next;
        }
        tmp->next = NULL;
        curr->next = tmp;
        curr = curr->next;
    }
    if(list1 == NULL) curr->next = list2;
    if(list2 == NULL) curr->next = list1;

    return dummy->next;
}

