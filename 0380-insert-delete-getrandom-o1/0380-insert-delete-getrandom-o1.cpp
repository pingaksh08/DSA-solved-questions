class RandomizedSet {
public:
    
    // hashmap + vector
    unordered_map<int, int> mp; // to track value with index
    vector<int> v; // to store values
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        
        int index = mp[val];
        int lastval = v.back();
        v[index] = lastval;
        v.pop_back();
        mp[lastval] = index;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */