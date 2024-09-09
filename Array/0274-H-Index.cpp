/*
題目：
https://leetcode.com/problems/h-index/description/

解說：
找出h值,滿足該publisher發出h的篇paper,每篇至少被cite h次
先sort,從最大值開始找h值,當篇數(即index n-i)大於被cite的次數(h),代表已經找到h的最大值,因為後續的citation值都會小於h

有使用到的觀念：
Array
*/

// #include "../code_function.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        int h = 0;
        sort(citations.begin(),citations.end());
        for(int i=n-1; i>=0; i--)
        {
            if(n-i > citations[i]) break;
            h = min(n-i,citations[i]); 
        }
        return h;
    }
};
