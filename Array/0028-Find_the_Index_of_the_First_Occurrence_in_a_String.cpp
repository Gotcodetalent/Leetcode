/*
題目：
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

解說：
直覺的linear scan, 逐個比對目標字串是否存在於給定的字串中。

有使用到的觀念：
可以使用KMP-Algo來達到更快的速度

*/

// #include "../code_function.h"
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size() - needle.size() + 1;
        for(int i=0; i<size; i++)
        {
            if(haystack.substr(i,needle.size()) == needle)
                return i;
        }
        return -1;
    }
};
