/*
題目：
https://leetcode.com/problems/sort-vowels-in-a-string/submissions/1410418990/

解說：
把字串s中的vowels記錄在另一個vector中,並以'#'替代s中的vowels
接著對sorting後的s進行scan,遇到'#'就從vector中取出一個填入

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char> vowel;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I'|| s[i] == 'O' || s[i] == 'U')
                {
                    vowel.push_back(s[i]);
                    s[i] = '#';
                }
        }

        sort(vowel.begin(), vowel.end());
        int curr = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '#')
            {
                s[i] = vowel[curr];
                curr++;
            }
        }

        return s;
    }
};
