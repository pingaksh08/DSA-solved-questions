class TimeMap {
public:
    // map + binary search
    unordered_map<string , vector<pair<int , string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";
        
        else if(mp[key][0].first > timestamp)
            return "";
        
        else{
           int n = mp[key].size();
           int low = 0 , high = n-1 , res = -1;
           
           while(low <= high){
               int mid = low + (high - low)/2 ;
               int currts = mp[key][mid].first;
               
               if(currts > timestamp) high = mid-1;
               else res = mid , low = mid+1; 
           } 
            
           return res == -1 ? "" : mp[key][res].second; 
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */