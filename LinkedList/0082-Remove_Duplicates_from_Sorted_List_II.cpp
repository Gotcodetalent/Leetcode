/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

解說：
可能會改變head, 所以使用一個dummy pointer指向head
preNode指向最後一個合法節點, nextNode遍歷所有節點
使用一個ump紀錄重複的val值

有使用到的觀念：
two pointers
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nextNode = head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* preNode = dummy;
        unordered_map<int,int> dup;
        while(nextNode)
        {
            ++dup[nextNode->val];
            nextNode = nextNode->next;
        }
        
        nextNode = head;

        while(nextNode)
        {
            if(dup[nextNode->val] == 1)
            {
                preNode = nextNode;
                nextNode = nextNode->next;
            }
            else{
                while(nextNode && dup[nextNode->val] > 1)
                {
                    //ListNode* tmp = nextNode;
                    nextNode = nextNode->next;
                    //delete(tmp);
                }
                preNode->next = nextNode;

            }
        }

        return dummy->next;
    }
};
