class Solution {
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       vector<pair<int, int>> v;
       for(int i=0 ; i<n ; i++){
           v.push_back({efficiency[i] , speed[i]});
       }
        
       sort(v.rbegin() , v.rend()); // sorting in decreasing order of efficiency
       priority_queue<int , vector<int> , greater<int>> minh; // min heap
       long totalspeed = 0 , ans = 0;
        
       for(int i=0 ; i<n ; i++){
           
           int currspeed = v[i].second;
           int currefficiency = v[i].first;
           
           // storing k engineers with maximum speed
           if(minh.size() == k){
               totalspeed -= minh.top(); // removing the speed before poping from the heap
               minh.pop();
           }
           
           minh.push(currspeed); // min heap of speeds
           totalspeed += currspeed; // total speed
           ans = max(ans , totalspeed * currefficiency); // ans as per the question 
       }
        
        return (ans%mod);
    }
};