/*
題目：
https://leetcode.com/problems/fraction-to-recurring-decimal/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 判斷結果是否為負數
        bool is_negative = (numerator < 0) ^ (denominator < 0);
        long long num = abs((long long)numerator);
        long long denom = abs((long long)denominator);

        // 計算整數部分
        long long integer = num / denom;
        long long frac = num % denom;

        string ret = is_negative && (integer > 0 || frac > 0) ? "-" : ""; 
        ret += to_string(integer);

        if (frac == 0) return ret; // 沒有小數部分

        ret += ".";

        // 處理小數部分
        unordered_map<long long, int> pos; // 紀錄餘數位置
        string frac_part = "";
        while (frac != 0) {
            if (pos.count(frac)) {
                // 插入括號表示循環
                frac_part.insert(pos[frac], "(");
                frac_part += ")";
                ret += frac_part;
                return ret;
            }

            // 記錄餘數位置
            pos[frac] = frac_part.size();
            frac *= 10;

            long long quotient = frac / denom;
            frac %= denom;

            frac_part += to_string(quotient);
        }

        ret += frac_part;
        return ret;
    }
};
