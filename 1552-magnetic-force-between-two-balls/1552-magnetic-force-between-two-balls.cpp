class Solution {
public:
    
    bool isvalid(vector<int>& position, int m , int val){
        int prev = position[0] , count=1;
        int n = position.size();
        for(int i=0 ; i<n ; i++){
            if(position[i] - prev >= val) {
             count++;
             if(count == m) return true;
             prev = position[i];
       
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
       int n = position.size(); 
       sort(position.begin() , position.end());
        
       int low = 0;
       int high = position[n-1];
       int res = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isvalid(position,m,mid)){
                res = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return res;
        
    }
};