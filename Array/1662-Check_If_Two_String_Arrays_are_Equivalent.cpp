/*
題目：
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size(), n2 = word2.size();
        string s1 = "", s2 = "";
        for(int i=0; i<n1; i++) {
            s1 += word1[i];
        }        
        for(int i=0; i<n2; i++) {
            s2 += word2[i];
        }

        bool ret = s1.compare(s2) == 0 ? 1 : 0;

        return ret;
    }
};
