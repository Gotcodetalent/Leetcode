/*
題目：
https://leetcode.com/problems/number-of-boomerangs/

解說：
對於每個 point, 紀錄與其有相同 dist 的 point 總數, 假設總數為 k ,能形成的 boomerang 為 k * (k - 1)  (k個點取2個點與起點組成boomerang)
每回合算出該 point 能形成幾個 boomerang 並加總即可

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int m = points.size();
        if(m < 3) return 0;

        int ans = 0;
        for(int i=0; i<m; i++)
        {
            unordered_map<int,int> ump;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=0; j<m; j++)
            {
                if(i != j)
                {
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
                    ump[dist]++;
                }
            }

            for(auto& p : ump) {
                if(p.second) ans += p.second * (p.second - 1);
            }

        }

        return ans;
    }
};
