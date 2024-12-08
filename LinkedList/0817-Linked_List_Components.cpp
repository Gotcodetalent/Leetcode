/*
題目：
https://leetcode.com/problems/linked-list-components/

解說：
題目為給予一個list, 以及要取list內的那些node, 判斷產生幾個component

先使用一個set紀錄採用的nodes, 並以bool變數紀錄目前是否在一個component中
遍歷所有node, 若有採用到該node且當前不在某個component中, 代表必須產生一個新的component來容納此node
若遍歷到某個node時,該node沒有在set中, 代表脫離了該component

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> uns(nums.begin(),nums.end());
        int ans = 0;
        bool InComponent = false;
        while(head)
        {
            if(uns.count(head->val))
            {
                if(!InComponent)
                {
                    InComponent = true;
                    ++ans;
                }
            }
            else InComponent = false;

            head = head->next;
        }

        return ans;
    }
};
