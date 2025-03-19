/*
題目：
https://leetcode.com/problems/minimum-time-to-repair-cars/?envType=daily-question&envId=2025-03-16

解說：
Sol 1. (slow) 使用 minHeap 逐個將目前所需最少維修時間的技師找出來, 直到滿足維修需求
Sol 2. (fast) 使用 Binary search, 尋找 valid 維修時間 (是否能在該時間內能維修所有車輛), 並持續更新所需時間之最小值 

有使用到的觀念：

*/

// #include "../code_function.h"
Sol 1.
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // current repair time, mechanic id, number of fixed cars
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> min_heap;
        
        for(int i = 0; i < ranks.size(); ++i)
        {
            min_heap.emplace(ranks[i], i, 1);
        }

        long long total_time = 0;

        for(int car = 0; car < cars; ++car)
        {
            auto [curr_time, id, num_fixed] = min_heap.top();
            min_heap.pop();
            total_time = curr_time;

            long long next_time = ranks[id] * (long long)(num_fixed + 1)*(num_fixed + 1);
            min_heap.emplace(next_time, id, num_fixed + 1);

        }

        return total_time;
    }
};

Sol 2.
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = high;

        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            if (fix_all(ranks, cars, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
private:
    bool fix_all(vector<int>& ranks, int& cars, long long times)
    {
        long long total = 0;
        for(int& rank : ranks)
        {
            total += (long long)sqrt(times / rank); // calculate production of each mechanic 
            if (total >= cars) return true;  
        }

        return false;
    }
};
