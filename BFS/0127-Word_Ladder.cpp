/*
題目：
https://leetcode.com/problems/word-ladder/

解說：
概念是使用BFS針對與beginWord差異一個字元的字串來搜尋endWord
使用一個set(dict)記錄目前尚未搜尋過的wordList內的字串,並使用一個queue(q)來記錄要搜尋的字串
剛開始確認endWord是否存在 (這樣第38行在match時就能直接返回答案)
接著插入beginWord到queue中,當queue不為空時代表queue中可能有解
依照FIFO將元素pop,並使用暴力法將可能的字串word列出,並檢查word是否為答案:
-> 若為ans,則返回 ladder + 1 (ladder代表轉換了ladder次但仍無法match,while迴圈每跑一圈就是一次,因為每圈都會測試所有鄰居)
-> 若不為ans, 則檢查word是否存在於未搜尋過的字串中,若存在則加入q,並從wordList內移除

有使用到的觀念：
BFS
*/

// #include "../code_function.h"
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int ladder = 1;

        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                string word = q.front();
                q.pop();
                for(int j=0; j<word.size(); j++)
                {
                    char c = word[j];
                    for(int k=0; k<26; k++)
                    {
                        word[j] = 'a' + k;
                        if(word == endWord) return ladder + 1; 
                        if(dict.find(word) != dict.end())
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }              
            ladder++;
        }

        return 0;
    }
};
