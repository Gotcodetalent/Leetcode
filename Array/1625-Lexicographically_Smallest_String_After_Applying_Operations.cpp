/*
題目：
https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

解說：
給予一個字串s代表一個數值,以及整數a,b
a可以無限次加在index為奇數的數上, b則代表s可以無限次的平移b個單位
找出在此操作限制下s的最小值

利用遞迴的方式以暴力法求出, 宣告一個set vistited來記錄所有排列組合,global變數ret則在遞迴中不斷的比較進行更新,並於最後返回
於dfs中使用add, rotate這兩個功能函式開始遞迴找解答
- 若set中以存在該排列組合代表已經比較過了, 則返回
- 若未找到則進行比較,並更新ret,接著進行下回合的遞迴

有使用到的觀念：
Recurrsive, Array
*/

// #include "../code_function.h"
class Solution {
public:
    unordered_set<string> visited;
    string ret;

    string add(string s, int a) {
        int n = s.size();
        for(int i=1; i<n; i+=2) {
            int curr = (s[i]-'0' + a) % 10;
            s[i] = curr + '0';
        }

        return s;
    }

    string rotate(string s, int b) {
        int n = s.size();
        string s1 = s.substr(n - b, b);
        string s2 = s.substr(0, n - b);

        return s1 + s2;
    }

    void dfs(string s, int a, int b) {
        if(visited.find(s) != visited.end()) {
            return;
        }
        ret = ret.compare(s) > 0 ? s : ret;
        visited.emplace(s);
        dfs(add(s, a), a, b);
        dfs(rotate(s, b), a, b);
    }

    string findLexSmallestString(string s, int a, int b) {
        ret = s;
        dfs(s, a, b);
        return ret;
    }
};
