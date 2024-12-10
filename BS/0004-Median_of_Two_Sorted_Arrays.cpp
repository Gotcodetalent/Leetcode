/*
題目：
https://leetcode.com/problems/median-of-two-sorted-arrays/

解說：


有使用到的觀念：
binary search, recursive

*/

// #include "../code_function.h"
Sol 1. :
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size() + nums2.size();
        vector<double> vec;
        for(int num : nums1) vec.push_back(num);
        for(int num : nums2) vec.push_back(num);
        sort(vec.begin(), vec.end());

        if(n % 2 == 0){
            return (vec[n/2] + vec [n/2 - 1])/2.0;
        }
        else return vec[n/2];
    }
};

Sol 2. :
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int total = nums1.size() + nums2.size();
        if(total % 2 == 0)
        {
            return (getKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,total/2)\
             + getKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,total/2 - 1))/2.0;
        }
        else return getKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,total/2);
    }

    int getKth(vector<int> nums1, int x1, int y1, vector<int> nums2, int x2, int y2, int k)
    {
        if(x1 > y1) return nums2[x2+k];
        if(x2 > y2) return nums1[x1+k];
        if(k == 0) return min(nums1[x1], nums2[x2]);

        int len1 = y1 - x1 + 1;
        int len2 = y2 - x2 + 1;

        int m1 = k * len1/(len1 + len2); //nums1 在k+1個數中提供了m1+1個數,初始值為長度比例*k
        int m2 = k - (m1 + 1);

        m1 += x1;
        m2 += x2;

        if(nums1[m1] < nums2[m2]) // nums1佔 k+1 個數的前 m1+1 個數
        {
            k = k - (m1 -x1 + 1); //找到了m1+1個數, 更新剩餘的數
            x1 = m1 + 1;
            y2 = m2;
        }
        else{
            k = k - (m2 -x2 + 1);
            x2 = m2 + 1;
            y1 = m1;
        }

        return getKth(nums1, x1, y1, nums2, x2, y2, k);
    }
};
