/*
題目：
https://leetcode.com/problems/copy-list-with-random-pointer/description/

解說：
clone 的套路就是使用 unordered_map, 以原始 node 為 index 來查找對應 copy node 的 Hash map

有使用到的觀念：

*/

// #include "../code_function.h"
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* clone = new Node(-1);
        Node* copy = clone;
        Node* curr = head;
        unordered_map<Node*,Node*> ump;
        while(curr)
        {
            Node* tmp = new Node(curr->val);
            ump[curr] = tmp; //以curr作為index mapping new list's node
            copy->next = tmp;
            copy = copy->next;
            curr = curr->next;
        }

        copy = clone->next;
        curr = head;

        while(curr) //對random pointer copy
        {
            copy->random = ump[curr->random];
            copy = copy->next;
            curr = curr->next;
        }

        return clone->next;
    }
};
