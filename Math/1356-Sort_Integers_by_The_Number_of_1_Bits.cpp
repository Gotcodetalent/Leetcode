/*
題目：
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int> count;
        vector<int> tmp(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++)
        {
            int cnt = 0;
            while(tmp[i]){
                cnt += tmp[i]&1;
                tmp[i] >>= 1;
            }
            count[arr[i]] = cnt;
        }

        auto compare = [&count](int& a, int& b){
            if(count[a] != count[b]) return count[a] < count[b];
            return a < b;
        };

        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};
