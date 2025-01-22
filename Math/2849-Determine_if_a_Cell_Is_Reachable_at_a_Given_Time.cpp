/*
題目：
https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

解說：
判斷 t 時間內是否能從 (sx, sy) 走到 (fx, fy)
Diff :　x = abs(fx - sx), y = abs(fy - sy)
mn = min(x, y) 代表可以共用的最大步數, 剩餘步數即為 abs(x - y), 最短距離 dist 便會是 mn + abs(x - y)
而依照題意我們可以走所有鄰接的格子, 所以當起終點相異時, 只要判斷最短距離 dist <= t 即可。
因為今天只要 dist <= t, 都能夠藉由鄰接的格子將剩餘的 t - dist 步 (0, 1, 2, ...) 給走完

*特殊情況為 "起終點相同" 且當 t 為 1 時, 便無法回到原點。

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        int mn = min(x,y);
        if(x == 0 && y == 0 && t == 1) return false;
        return (mn + abs(x-y)) <= t;
    }
};
