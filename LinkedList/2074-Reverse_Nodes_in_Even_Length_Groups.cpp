/*
題目：
https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* prev = dummy;//上個群組的末點
        ListNode* curr = head;
        int group_cnt = 1;
        while(curr)
        {
            ListNode* group_start = curr;//當前群組起點
            int count = 0;
            while(curr && count < group_cnt) //curr移動到下個群組起始點
            {
                ++count;
                curr = curr->next;
            }

            if(count % 2 == 0)
            {
                ListNode* rev = reverse(count, group_start); //反轉後group_start變為末點
                prev->next = rev; //上個群組末點連接此群組起點
                group_start->next = curr; //此群組末點連接下個群組起點
                prev = group_start; //更新prev
            }
            else{
                prev = group_start; //若長度為奇數, 則更新prev為當前群組起點
                while(--count) prev = prev->next; //走到此群組的end point
            }
            ++group_cnt;
        }

        return dummy->next;
    }
private:
    ListNode* reverse(int group_cnt, ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i=0; i<group_cnt; i++)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
};
