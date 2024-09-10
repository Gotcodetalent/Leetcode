/*
題目：
https://leetcode.com/problems/insert-delete-getrandom-o1/

解說：
實作出一個可以插入、移除元素,並返回集合中隨機數的class
使用一個array(temp)來儲存插入的元素,並使用集合set來儲存元素在array中的位置
insert時若找得到元素則返回false, 若找不到則插入array中,並將位置紀錄在set
remove時若找不到則返回flase,若找得到則將array最後一個元素last覆蓋到要刪除的元素val上,接著移除掉last,在O(1)時間完成刪除
接著對set中的紀錄更新,將val原本的位置set[val]賦予給last,並刪除val

有使用到的觀念：
hash, set
*/

// #include "../code_function.h"
class RandomizedSet {
private:
    unordered_map<int,int> set;
    vector<int> temp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val) != set.end()) return false;
        else
        {
            temp.push_back(val);
            set[val] = temp.size() - 1;

            return true;
        }
    }
    
    bool remove(int val) {
        if(set.find(val) == set.end()) return false;
        else
        {
            int last = temp.back();
            temp[set[val]] = temp.back();

            temp.pop_back();
            set[last] = set[val];
            set.erase(val);

            return true;
        }
    }
    
    int getRandom() {
        return temp[rand() % temp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
