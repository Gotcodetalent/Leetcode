/*
題目：
https://leetcode.com/problems/merge-two-sorted-lists/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        while(list1 != nullptr)
        {
            ListNode* tmp = new ListNode(0);
            tmp->val = list1->val;
            list1 = list1->next;
            curr->next = tmp;
            curr = curr->next;
        }
        while(list2 != nullptr)
        {
            ListNode* tmp = new ListNode(0);
            tmp->val = list2->val;
            list2 = list2->next;
            curr->next = tmp;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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
    while(list1 != NULL)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = list1->val;
        tmp->next = NULL;
        list1 = list1->next;
        curr->next = tmp;
        curr = curr->next;
    }
    while(list2 != NULL)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = list2->val;
        tmp->next = NULL;
        list2 = list2->next;
        curr->next = tmp;
        curr = curr->next;
    }

    struct ListNode* merge = dummy->next;
    free(dummy);
    return merge;
}
