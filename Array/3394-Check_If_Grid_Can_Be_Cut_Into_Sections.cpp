/*
題目：
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

解說：
題目為給定一些矩形, 驗證是否可以有 2 條水平 or 垂直線能夠將這些矩形分類在三個區域, 並滿足：
1. 每個區域至少都要有一個矩形
2. 每個矩形不能跨區
* 此題中矩形不會有 overlappong 的問題

解法為針對 水平 && 垂直 去驗證是否有一種能夠產生三條線, 若可以則為 true

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const int num = rectangles.size();
        sort(rectangles.begin(), rectangles.end(),[](const vector<int>& a, const vector<int>& b){return a[1] < b[1];});
        int y_end = rectangles[0][3];
        int y_start = rectangles[0][1];
        bool y = true;
        int y_count = 1;

        for(auto& r : rectangles)
        {
            int curr_start = r[1];
            int curr_end = r[3];
            
            if (curr_start >= y_end)
            {
                ++y_count;
            }

            y_end = max(y_end, curr_end);
            y_start = min(y_start, curr_start);
        }

        sort(rectangles.begin(), rectangles.end(),[](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        int x_end = rectangles[0][2];
        int x_start = rectangles[0][0];
        bool x = true;
        int x_count = 1;

        for(auto& r : rectangles)
        {
            int curr_start = r[0];
            int curr_end = r[2];
            
            if (curr_start >= x_end)
            {
                ++x_count;
            }
            x_end = max(x_end, curr_end);
            x_start = min(x_start, curr_start);
        }

        if(x_count <= 2) x = false;
        if(y_count <= 2) y = false;

        return (x || y) ;
    }
};
