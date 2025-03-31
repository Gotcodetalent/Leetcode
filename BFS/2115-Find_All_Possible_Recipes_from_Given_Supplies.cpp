/*
題目：
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

解說：
1. BFS
2. DFS

有使用到的觀念：

*/

// #include "../code_function.h"
BFS:
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree; // 記錄每道食譜還需要多少原料
        unordered_map<string, vector<string>> graph; // 記錄某個原料可解鎖的食譜
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> ans;

        // 1. 建立 indegree table & dependency graph
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size(); // 這道食譜需要的原料數量
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]); // 當 `ing` 可用時，可解鎖 `recipes[i]`
            }
        }

        // 2. 將現有 `supplies` 放入 queue
        for (const string& s : supplies) {
            q.push(s);
        }

        // 3. 拓撲排序 (BFS)
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            // 若該 item 是食譜 (存在於 inDegree)，則加入答案
            if (inDegree.count(item)) {
                ans.push_back(item);
            }

            // 該 item 是某些食譜的原料，減少對應食譜的 indegree
            for (const string& recipe : graph[item]) {
                if (--inDegree[recipe] == 0) { // 當該食譜 indegree 變為 0，表示可以製作
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};

DFS:
class Solution {
public:
    unordered_map<string, bool> complete; //紀錄食譜是否可完成
    unordered_set<string> supplySet; //用於確認是否為原料
    unordered_set<string> recipeSet; //用於確認是否為食譜
    unordered_map<string, int> recipeIndex; //搜尋當前食譜的 index
    unordered_set<string> visited; //DFS prune, 當有食譜被搜尋過時, 其他遞迴便可不必再去確認
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        supplySet = unordered_set<string>(supplies.begin(), supplies.end());
        recipeSet = unordered_set<string>(recipes.begin(), recipes.end());

        for(int i = 0; i < recipes.size(); ++i) //紀錄食譜的 index
        {
            recipeIndex[recipes[i]] = i;
        }

        for(int i = 0; i < recipes.size(); ++i) //確認食譜可否被製作出來
        {
            if(check(i, recipes, ingredients, supplies))
            {
                ans.push_back(recipes[i]);
            }
        }    

        return ans;
    }
private:
    bool check(int index, vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        if(complete.count(recipes[index])) return true;
        if(visited.count(recipes[index])) return false;

        visited.insert(recipes[index]);

        for(int i = 0; i < ingredients[index].size(); ++i)
        {
            if(inRecipe(ingredients[index][i]))
            {
                int location = findIndex(ingredients[index][i]);
                if(!check(location ,recipes, ingredients, supplies))
                {
                    return false;
                }
            }
            else if(!inSupplies(ingredients[index][i]))
            {
                return false;
            }
        }
        
        complete[recipes[index]] = true;
        return true;
    }

    int findIndex(string& ingredient)
    {
        return recipeIndex[ingredient];
    }

    bool inRecipe(string& ingredient)
    {
        if(recipeSet.count(ingredient))
        {
            return true;
        }
        
        return false;
    }

    bool inSupplies(string& ingredient)
    {
        if(supplySet.count(ingredient))
        {
            return true;
        }
        
        return false;
    }
};
