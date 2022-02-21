/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

 // @lc code=start
class RandomizedSet {
    // values are unique, so unordered_map works always in o(1)
    unordered_map<int, int> positions;
    vector<int> v;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (positions.count(val)) return false;
        int pos = v.size();
        positions[val] = pos;
        v.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (positions.count(val) == 0)return false;
        int pos = positions[val];
        v[pos] = v.back();
        positions[v.back()] = pos;
        v.pop_back();
        positions.erase(val);
        return true;
    }

    int getRandom() {
        return v[(int)(rand() % v.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 // @lc code=end

