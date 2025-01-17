/*
題目：
https://leetcode.com/problems/neighboring-bitwise-xor

解說：
XOR 特性為 交換性 && 相同運算2次後會還原, 且derived[i] = original[i] ^ original[i+1]
因此得出以下式子:
derived[0] = original[0] ^ original[1]
derived[1] = original[1] ^ original[2]
derived[2] = original[2] ^ original[3]
......
derived[n-2] = original[n-2] ^ original[n-1]
derived[n-1] = original[n-1] ^ original[0]

所以將 derived 所有元素進行 XOR 運算後會變成:
derived[0] ^ derived[1] ^ derived[2] ... derived[n-2] ^ derived[n-1] 
= {original[0] ^ original[1]} ^ {original[1] ^ original[2]} ... ^ {original[n-2] ^ original[n-1]} ^ {original[n-1] ^ original[0]}
= original[0] ^ {original[1] ^ original[1]} ^ {original[2] ^ original[2]} ... ^ {original[n-2] ^ original[n-2]} ^ {original[n-1] ^ original[n-1]} ^ original[0]
= original[0] ^ original[0] 
= 0


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int i = 0;
        for(int& d : derived) 
        {
            i ^= d;
        }

        return i == 0;
    }
};
