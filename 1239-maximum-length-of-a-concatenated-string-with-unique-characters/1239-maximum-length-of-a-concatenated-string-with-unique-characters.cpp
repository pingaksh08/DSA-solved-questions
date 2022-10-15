class Solution {
public:
    
    bool compare(vector<int> &visited , string curr){
        //self check for repeating characters
        vector<int> hash(26, 0);
        for(int i=0 ; i<curr.length() ; i++){
            if(hash[curr[i] - 'a'] == 1) return false;
            hash[curr[i] - 'a'] = 1;
        }
        
        for(int i=0 ; i<curr.length() ; i++){
            if(visited[curr[i] - 'a'] == 1) return false;
        }
        
        return true;
    }
    
    int solve(int index , vector<string>& arr , vector<int> &visited , int length){
       // base case
       if(index == arr.size()) return length;
       
        // recursion
        string curr = arr[index];
        if(compare(visited , curr) == false){
            // skip if it already exists
            return solve(index+1 , arr , visited , length);
        }
        else{
            // two choices --> pick or skip
            // pick
            for(int i=0 ; i<curr.length() ; i++){
                // marking curr string chars visited
                visited[curr[i] - 'a'] = 1;
            }
            // updating length
            length += curr.length();
            int op1 = solve(index+1 , arr , visited , length);
            
            // skip
            for(int i=0 ; i<curr.length() ; i++){
                // unmarking curr string chars 
                visited[curr[i] - 'a'] = 0;
            }
             // removing length
            length -= curr.length();
            int op2 = solve(index+1 , arr , visited , length);
            
            return max(op1 , op2);
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> visited(26, 0);
        return solve(0 , arr , visited , 0);
    }
};