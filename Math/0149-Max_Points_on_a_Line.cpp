/*
題目：
https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

解說：
找出通過同一條直線的最大point數
有 n 個點, 則遍歷所有直線時, 可分為通過第 1, 2, 3, ..., n-1 個點的直線群組
每個群組內以第 i 個點為基準點, 擁有相同斜率的點必定共線
而為了確保斜率計算上沒有誤差, 使用gcd將斜率化為整數比, 避免浮點數產生的誤差

*注意水平、垂直線

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            map<pair<int,int>, int> cnt;
            int mx_pts = 0;
            int same_pts = 1;
            for(int j=i+1; j<n; j++)
            {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) ++same_pts;
                else{
                    mx_pts = max(mx_pts, ++cnt[getSlope(points[i], points[j])]);
                }
            }
            ans = max(ans, mx_pts + same_pts);
        }

        return ans;
    }

    pair<int,int> getSlope(vector<int>& A, vector<int>& B){
        const int dx = A[0] - B[0];
        const int dy = A[1] - B[1];

        if(dx == 0) return {A[0], 0}; //vertical
        if(dy == 0) return {0, A[1]}; //horizontal

        int d = gcd(dx, dy);

        return {dx/d, dy/d};
    }

    int gcd(int m, int n){
        return n == 0 ? m : gcd(n, m%n); 
    }
};
