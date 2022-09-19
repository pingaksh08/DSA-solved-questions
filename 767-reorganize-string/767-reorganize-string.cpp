class Solution {
public:
    // max heap
    string reorganizeString(string s) {
        int n = s.size();
        
        unordered_map<char, int> mp;
        for(int i=0 ; i<n ; i++) mp[s[i]]++;
        
        priority_queue<pair<int , char>> maxh;
        for(auto it : mp){
            maxh.push({it.second , it.first});
        }
        pair<int, char> b = {-1 , '&'};
        string ans = "";
        while(!maxh.empty()){
            auto temp = maxh.top();
            maxh.pop();
            
            ans += temp.second;
            temp.first--;
            
            if(b.first > 0){
                maxh.push(b);
            }
            
            b = temp;
        }
        
        if(n == ans.size())
            return ans;
        
        return "";
    }
};