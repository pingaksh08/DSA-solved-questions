class Solution {
public:
    bool reorderedPowerOf2(int n) {
       vector<string> v;
        for(int i=0 ; i<=30 ; i++){
            int val = pow(2,i);
            v.push_back(to_string(val));
        }
        
        for(int i=0 ; i<=30 ; i++){
            sort(v[i].begin(), v[i].end());
        }
        
        string str = to_string(n);
        sort(str.begin(), str.end());
        
        for(int i=0 ; i<=30 ; i++){
            if(str == v[i]){
                return true;
            }
        }
        
        return false;
    }
};