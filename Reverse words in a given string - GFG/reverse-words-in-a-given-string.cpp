// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans = "";
        vector<string> v;
        string temp = "";
        
        for(int i=0 ; i<S.length() ; i++){
            if(S[i] != '.'){
                temp = temp + S[i];
            }
            else{
                v.push_back(temp);
                temp = "";
            }
        }
        v.push_back(temp); // last pair of words
        for(int i=v.size()-1 ; i>=0 ; i--){
            ans = ans + v[i] + '.';
        }
        ans.pop_back(); // to remove extra . at the end
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends