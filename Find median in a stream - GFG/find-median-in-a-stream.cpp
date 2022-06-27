// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> maxh;
    priority_queue<int , vector<int> , greater<int>> minh;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxh.empty() or maxh.top() >= x)
         maxh.push(x);
         
        else
         minh.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxh.size() > minh.size() + 1){
            minh.push(maxh.top());
            maxh.pop();
        }
        
        else if(minh.size() > maxh.size() + 1){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
    
        if(maxh.size() == minh.size()){
            return (((double)maxh.top() + (double)minh.top())/2.0);
        }
       
       return maxh.size() > minh.size() ? (double)maxh.top() : (double)minh.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends