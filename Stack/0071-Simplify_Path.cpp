/*
題目：
https://leetcode.com/problems/simplify-path/

解說：
遇到'/'就忽略, 遇到一個directory就記錄下來,接著判斷要執行什麼動作
例如: ".."要返回上個路徑, 則必須執行pop

若最後ans為 "" 代表留在當前目錄, 返回"/"

有使用到的觀念：

*/

// #include "../code_function.h"
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string str = "";
        for(int i=0; i<path.length(); i++)
        {
            if(path[i] == '/') continue;
            string str = "";
            while(i < path.size() && path[i] != '/')
            {
                str += path[i];
                i++;
            }

            if(str == "." ) continue;
            else if(str == ".."){
                if(!stk.empty()) stk.pop();
            }
            else stk.push(str); 
        }

        string ans = "";

        while(!stk.empty())
        {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        
        if(ans == "") return "/";
        else return ans;
    }
};
