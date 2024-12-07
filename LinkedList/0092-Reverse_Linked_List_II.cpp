/*
題目：
https://leetcode.com/problems/reverse-linked-list-ii/

解說：
部分反轉 -> 使用插入的方式 (插入right - left 次)
ex:
1,2,3,4,5 (reverse 2,3,4)
left = 2, right = 4, insert 2 times
prev = 1, curr = 2

step 1. 1,3,2,4,5
step 2. 1,4,3,2,5

有使用到的觀念：

*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        
        for(int i=1; i < left; ++i) prev = prev->next; //找到left 前一個node
        
        ListNode* curr = prev->next; //找到要執行插入的起始點
        ListNode* nextNode = nullptr; 
        
        for(int i=0; i<right-left; ++i)
        {
            nextNode = curr->next; //curr的next node
            curr->next = nextNode->next; // curr連到 next node的next node
            nextNode->next = prev->next; // curr的next node 連到 prev的next node
            prev->next = nextNode; // prev連到curr的next node
        }

        return dummy->next;
    }
};
