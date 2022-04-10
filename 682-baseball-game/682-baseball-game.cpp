class Solution {
public:
    int calPoints(vector<string>& ops) {
        // solution is straight forward.
       stack<int> s;
       int itm1, itm2, ans=0; 
        
       for(auto it : ops){
           if(it == "C"){
               s.pop();
           }
           
           else if(it == "D"){
               s.push(2*s.top());
           }
           
           else if(it == "+"){
               itm1 = s.top();
               s.pop();
               itm2 = itm1 + s.top();
               s.push(itm1);
               s.push(itm2);
           }
           else{
               s.push(stoi(it));
           }
       }
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        
        return ans;
    }
};