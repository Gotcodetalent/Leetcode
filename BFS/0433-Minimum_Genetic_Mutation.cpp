/*
題目：
https://leetcode.com/problems/minimum-genetic-mutation/

解說：
與0127 Word_Ladder概念相同

有使用到的觀念：
BFS
*/

// #include "../code_function.h"
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if(!dict.count(endGene)) return -1;

        queue<string> q;
        vector<char> genes = {'A','C','T','G'};
        q.push(startGene);
        int mM = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                string gene = q.front();
                q.pop();
                for(int j=0; j<gene.size(); j++)
                {
                    char ch = gene[j];
                    for(char g: genes)
                    {
                        gene[j] = g;
                        if(gene == endGene) return mM + 1;
                        if(dict.find(gene) != dict.end())
                        {
                            dict.erase(gene);
                            q.push(gene);
                        }
                    }
                    gene[j] = ch;
                }

            }
            mM++;
        }

        return -1;
        
    }
};
