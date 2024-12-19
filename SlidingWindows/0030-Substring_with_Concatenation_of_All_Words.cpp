/*
題目：
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

解說：
先記錄 words 中各個 word 的頻率
接著從 0 ~ word length - 1 開始滑動 (大於等於 word length 後續的都是重複的), 尋找可能解
step :
1. 確保當前擷取到的字串是存在的, 若存在則驗證頻率, 超過頻率則從 left 開始縮減
2. 若不存在則放棄前面擷取的, 從 right 頭開始尋找

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordsCount = words.size();
        int wordslen = words[0].length(); //window大小
        int stringlen = s.length();
        int total = wordslen * wordsCount;
        vector<int> ans;

        if(s.length() < total) return {};

        unordered_map<string,int> ump;
        for(string& word : words) ++ump[word];

        for(int i=0; i<wordslen; i++) //i 為 window起點
        {
            int l=i, r=i, count = 0;
            unordered_map<string,int> freq;
            while(r + wordslen <= stringlen)
            {
                string currword = s.substr(r, wordslen);
                r+=wordslen;
                
                if(ump.count(currword)) // sub exist in ump
                {
                    ++freq[currword];
                    ++count;
                    while(freq[currword] > ump[currword])
                    {
                        string leftword = s.substr(l,wordslen);
                        --freq[leftword];
                        --count;
                         l+= wordslen;
                    }

                    if(count == wordsCount) ans.push_back(l);
                }
                else // doesn't exist then reset
                {
                    freq.clear();
                    count = 0;
                    l = r;
                }
            }            
        }

        return ans;
    }
};

<以下目前已 exceed time limit>
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> ump;
        int windowSize = words[0].length();
        int wordCount = words.size();
        int total = windowSize*wordCount;

        if(s.length() < total)
        return {};

        vector<int> ans;
        for(string str : words)
        {
            ump[str]++;
        }

        for(int i=0; i<=s.length()-total; i++)
        {
            unordered_map<string,int> freq;
            int j=0; //從word[0]開始找起
            for(int j=0; j<wordCount; j++)
            {
                string str = s.substr(i+j*windowSize, windowSize);
                ++freq[str];
                if(freq[str] > ump[str]) break;

                if(j+1 == wordCount) ans.push_back(i);
            }
        }

        return ans;
    }
};
