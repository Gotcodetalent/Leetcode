/*
題目：
https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

解說：
如果兩隻螞蟻相遇，等價於「穿過對方」而繼續向各自的方向前進。
換句話說，可以將螞蟻的路徑視為不變，直接看每隻螞蟻走到木板邊緣所需的時間。
所以只要找出到邊緣最大的距離即可

ex: 左側螞蟻 A 到右側的距離是 X, 右側螞蟻 B 到左側的距離是 Y
時間過了 t 秒後相遇, A 距離邊緣還有 X - t, B 距離邊緣還有 Y - t
如果變換方向, 則 A 接下來要走 Y - t 的距離後才會掉落, B 則是 X - t
則 A, B 兩隻螞蟻中最後掉落的時間變成 max(t + (X - t) , t + (Y - t)), 即 max(X, Y) 

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int lmax = left.empty() ? 0 : left.back() - 0;
        int rmax = right.empty() ? 0 : n - right[0];

        return max(lmax,rmax); 
    }
};
