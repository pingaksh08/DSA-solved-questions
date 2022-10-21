class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
      unordered_map<int , vector<int>> mp;
      for(int i=0 ; i<arr.size() ; i++){
          mp[arr[i]].push_back(i);
      }
      
      for(auto it : mp){
          if(it.second.size() > 1){
              for(int i=0 ; i<it.second.size()-1 ; i++){
                  if(abs(it.second[i] - it.second[i+1]) <= k)
                      return true;
              }
          }
      }
        
        return false;
    }
};