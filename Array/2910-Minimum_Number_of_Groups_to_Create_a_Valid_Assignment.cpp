/*
題目：
https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/

解說：
1.同個箱子的球號碼要相同
2.如果有多顆相同號碼的球可以放不同箱子
3.最大箱子只能比最小箱子多放一顆球

假設可分類為一個箱子有 x 個 or x+1 個, x的最大值為陣列中出現頻率最少的值
a = freq/(x+1) , b = freq%(x+1)
如果 b == 0 則代表可以剛好分成 a 個 x+1 組
若 b != 0， x-b 的意涵代表著將還差 b 個就可以湊成一組 x 個
此時如果 x-b <= a 時，代表我們可以從 a 個組中個別抽一個湊成一組新的 size 為 x 的組
若 x-b > a 則代表無法分割成 x 組與 x+1 組


有使用到的觀念：
Hash table, Greedy
*/

// #include "../code_function.h"
class Solution {
public:
    int findMin(int x, vector<int> freq)
    {
        int sum = 0;
        for(const auto& c: freq)
        {
            int a = c/(x+1);
            int b = c%(x+1);
            if(b == 0) sum += a;
            else if((x-b) <= a) sum += (a+1);
            else return -1;
        }

        return sum;
    }

    int minGroupsForValidAssignment(vector<int>& balls) {
        const int n = balls.size();
        unordered_map<int,int> count;
        vector<int> freq;
        for(int i=0; i<n; i++) count[balls[i]]++;
        for(auto& pair: count) freq.push_back(pair.second);

        sort(freq.begin(), freq.end());
        int boxes = INT_MAX; 
        for(int i=1; i<=freq[0]; i++)
        {
            int tmp = findMin(i,freq);
            if(tmp != -1) boxes = min(boxes, tmp);
        }

        return boxes;
    }
};
