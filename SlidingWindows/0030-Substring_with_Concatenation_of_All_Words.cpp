/*
題目：
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

解說：


有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;
        int wordLength = words[0].length();  // 單字長度
        int wordCountTotal = words.size();   // 單字數量
        int totalLength = wordLength * wordCountTotal;  // 所有單字的總長度
        
        if (s.length() < totalLength) return {};  // 如果字串長度不足，返回空

        // 初始化 wordCount (記錄每個單字的出現次數)
        for (const string& word : words) {
            wordCount[word]++;
        }

        vector<int> result;

        // 外層循環，從 0 到 wordLength-1，模擬滑動視窗的開始位置
        for (int i = 0; i < wordLength; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> windowCount;

            while (right + wordLength <= s.length()) {
                string currentWord = s.substr(right, wordLength);  // 提取當前字
                right += wordLength;  // 右指針向右移動

                if (wordCount.count(currentWord)) {
                    windowCount[currentWord]++;
                    count++;

                    // 如果單字出現的次數超過要求，左指針向右移動，縮小窗口
                    while (windowCount[currentWord] > wordCount[currentWord]) {
                        string leftWord = s.substr(left, wordLength);
                        windowCount[leftWord]--;
                        left += wordLength;
                        count--;
                    }

                    // 如果計數達到單字數量，說明找到了一個符合的子字串
                    if (count == wordCountTotal) {
                        result.push_back(left);
                    }
                } else {
                    // 如果當前字不在 words 中，重置窗口
                    windowCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};


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
