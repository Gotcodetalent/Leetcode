/*
題目：
https://leetcode.com/problems/rotate-list/

解說：
n : list 長度
k%n : 實際 rotate 次數
j : node 之 index 
n - k%n + j : index 為 j 的 node rotate 後, 其 value 應該被代換為 index 為 n - k%n + j 的 node value

有使用到的觀念：

*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> nodeVal;
        ListNode* tmp = head;
        int n=0;
        while(tmp!=nullptr)
        {
            nodeVal.push_back(tmp->val);
            tmp = tmp->next;
            ++n;
        }
        tmp = head;
        int j=0;
        while(tmp!=nullptr)
        {
            tmp->val = nodeVal[(n-k%n+j)%n];
            tmp = tmp->next;
            ++j;
        }

        return head;
    }
};
