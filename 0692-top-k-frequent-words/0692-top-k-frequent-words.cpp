class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string , int> mp;
      for(auto it : words) mp[it]++;
        
      priority_queue<pair<int,string>> maxh;
        
        for(auto it : mp){ 
            maxh.push({-it.second , it.first});
             if(maxh.size() > k){
                maxh.pop();
            }
        }
        
        vector<string> ans;
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};