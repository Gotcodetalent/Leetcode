/*
題目：
https://leetcode.com/problems/non-overlapping-intervals

解說：
有多個區間,找出需要移除區間數的最小值,使得剩餘區間都不會重疊
想像有多個會議,但有些會重疊,要移除多少個才能使能參加的會議數最多(即 移除最少)
將開始時間(start)由晚到早排序(或將結束時間由早到晚),接著往前查看鄰近的會議的結束時間是否超過目前會議的開始時間
- 若Y,則移除 (line 28)
- 若N,則更新目前的開始時間 (line 31)

#如果將開始時間由早到晚or結束時間由晚到早排序,可能會選到一些大區間使得後續的小區間被覆蓋,這樣就不是min number of removed interval

有使用到的觀念：
Greedy, Array

*/
bool cmp(vector<int> &a,vector<int> &b) {
	return a[0] > b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end(),cmp);
        int start = intervals[0][0];
        int rm = 0;
        for(int i=1; i<n; i++)
        {
            if(intervals[i][1] > start) rm++;
            else
            {
                start = intervals[i][0];
            }
        }

        return rm;
    }
};
