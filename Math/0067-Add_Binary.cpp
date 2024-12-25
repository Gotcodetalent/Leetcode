/*
題目：
https://leetcode.com/problems/add-binary/

解說：
當a, b還沒遍歷完 or 有進位(carry)要處理時, 計算每回合的sum, 並計算出餘數&進位

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int carry = 0;
        string ans = "";
        while(alen || blen || carry > 0)
        {
            int bitA = alen > 0 ? a[alen-1]-'0' : 0; 
            int bitB = blen > 0 ? b[blen-1]-'0' : 0;
            
            int sum = bitA + bitB + carry;
            ans += (sum%2) + '0';
            carry = sum/2;

            if(alen) alen--;
            if(blen) blen--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
