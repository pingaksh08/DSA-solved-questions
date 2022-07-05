// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> temp1 , temp2;
        for(int i=0 ; i<n ; i++){
            if(arr[i] < 0) temp1.push_back(arr[i]);
            else temp2.push_back(arr[i]);
        }
        int n2 = temp2.size();
        for(int i=0 ; i<n2 ; i++){
            arr[i] = temp2[i];
        }
        for(int i=0 ; i<temp1.size() ; i++){
            arr[n2 + i] = temp1[i];
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends