/*
題目：
https://leetcode.com/problems/find-the-winner-of-an-array-game/


解說：
給定k值,當有某個整數贏了k次時,遊戲便結束
使用兩個pointer指向winner以及challenger
- if win, winner的win_count++, 指向challenger的pointer變為指向下一個challenger 
- if lose, challenger的win_count++, 將winner設置為challenger, 並把指向challenger的pointer指向為原challenger的下一位

即使k很大,每一輪最多就是贏n-1次,因此先達到n-1次的人一定是贏家

#目前解法未優化,為第一版直覺解法

有使用到的觀念：
greedy, two pointers
*/

// #include "../code_function.h"
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int n = arr.size();
        unordered_map<int,int> win_count;
        int i = 0, j = 1, winner = 0;
        while(k - win_count[winner])
        {
            if(arr[i%n] > arr[j%n])
            {
                winner = i%n;
                win_count[i%n]++; 
                j++;
            }
            else 
            {
                winner = j%n; 
                win_count[j%n]++;
                i = j;
                j++;
            }

            if(win_count[winner] >= n-1) break; //n distinct integer, the worst case is each round each element beats one element, the best case is an element beats n-1 element in one round
        }

        return arr[winner];
    }
};
