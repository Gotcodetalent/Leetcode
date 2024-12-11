/*
題目：
https://leetcode.com/problems/integer-to-roman/

解說：
1 <= num <= 3999, 因此可以暴力解, 列出所有位數會使用到的羅馬數字

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
