/*
題目：
https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int black = 0, white = 0, op = INT_MAX;
        int l = 0, r = 0;
        while(r < blocks.length())
        {
            if(blocks[r] == 'W') ++white;
            else ++black;

            if(r - l + 1== k)
            {
                op = min(op, white);
            }
            else if(r - l + 1> k)
            {
                black = blocks[l] == 'B' ? black - 1 : black;
                white = blocks[l] == 'W' ? white - 1 : white;
                l++;
                op = min(op, white);
            }
            ++r;
        }

        return op == INT_MAX ? 0 : op;
    }
};
