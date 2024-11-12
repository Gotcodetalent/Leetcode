/*
題目：
https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

解說：
Sol 1.
以Gray code概念遞迴求出

Sol 2.
Gray code, f(n)=n⊕(n>>1)
將數字 n 對應到 Gray code 表示下的 g(n)，這樣題目就等價於在 Gray code 序列中找到 g(n) 到 g(0) 的最短步驟數
（即從 Gray code 的 g(n) 轉變到 g(0) 所需的位元翻轉次數, 題目給予的操作方式能滿足Gray code序列的變換）

有使用到的觀念：

*/
// #include "../code_function.h"
class Solution1 {
    unordered_map<string, int> ump;
    unordered_map<string, int> ump2;
public:
    int minimumOneBitOperations(int n) 
    {
        string str = bitset<32>(n).to_string();
        return dfs(str);
    }

    int dfs(string n)
    {
        if(n == "0") return 0;
        if(n == "1") return 1;
        if(ump.find(n) != ump.end()) return ump[n];

        if(n[0] == '0') return dfs(n.substr(1));

        string m = n.substr(1);
        string p = m;
        p[0] = '1';
        for(int i = 1; i < p.size(); i++)
            p[i] = '0';
        ump[n] = dfs2(m) + 1 + dfs(p);
        return ump[n];
    }

    int dfs2(string n)
    {
        if(n == "0") return 1;
        if(n == "1") return 0;
        if(ump2.find(n) != ump2.end()) return ump2[n];

        if(n[0] == '1')
            ump2[n] = dfs(n.substr(1));
        else
        {
            string m = n.substr(1);
            string p = m;
            p[0] = '1';
            for(int i = 1; i < p.size(); i++)
                p[i] = '0';
            ump2[n] = dfs2(m) + 1 + dfs(p);
        }

        return ump2[n];
    }
};

class Solution2 {
public:
    int minimumOneBitOperations(int n) {
        return grayToBinary(n);
    }

private:
    // 將 Gray Code 轉換為二進制數
    int grayToBinary(int num) {
        int res = 0;
        while (num > 0) {
            res ^= num;
            num >>= 1;
        }
        return res;
    }
};
