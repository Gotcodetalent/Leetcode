/*
題目：
https://leetcode.com/problems/add-two-numbers/

解說：
每一位相加後留下進位,直到pointer皆指向NULL且進位為0

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* curr = ret;
        int carry = 0; //進位
        while(l1 != nullptr || l2 != nullptr || carry) {
            int tmp = carry;
            if(l1 != nullptr) {
                tmp += l1->val;
                l1 = l1 -> next;
            }
            if(l2 != nullptr) {
                tmp += l2->val;
                l2 = l2->next;
            }
            carry = tmp/10;
            curr -> next = new ListNode(tmp % 10);
            curr = curr->next;
        }

        return ret->next;
    }
};
