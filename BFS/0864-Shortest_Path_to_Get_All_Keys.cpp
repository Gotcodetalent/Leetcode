/*
題目：
https://leetcode.com/problems/shortest-path-to-get-all-keys/

解說：
使用一個 int 表示目前狀態
000xxxxx | 000yyyyy | 00kkkkkk
使用 3Darray 紀錄是否有拜訪過。

有使用到的觀念：

*/
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int all_keys = 0;
        queue<int>q;

        vector<vector<vector<int>>> seen(m, vector<vector<int>>(n, vector<int>(64, 0)));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                char ch = grid[i][j];
                if(ch == '@')
                {
                    q.push((i << 16) | (j << 8));
                    seen[i][j][0] = 1;
                }else if(ch >= 'a' && ch <= 'f')
                {
                    all_keys |= (1 << (ch - 'a'));
                }
            }

        int dir[5] = {1, 0, -1, 0, 1};

        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int tmp = q.front();
                q.pop();

                int x = tmp >> 16;
                int y = (tmp >> 8) & 0xFF;
                int keys = tmp & 0xFF;
                if(keys == all_keys) return steps;
                for(int i = 0; i < 4; i++)
                {
                    int nkeys = keys;
                    int nx = x + dir[i];
                    int ny = y + dir[i+1];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    const char ch = grid[nx][ny];
                    if(ch == '#') continue;
                    if(ch >= 'A' && ch <= 'F' && !(keys & (1 << (ch-'A')))) continue;

                    if(ch >= 'a' && ch <= 'f') nkeys |= (1 << (ch-'a'));
                    if(seen[nx][ny][nkeys])continue;
                    q.push((nx << 16) | (ny << 8) | nkeys);
                    seen[nx][ny][nkeys] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};
