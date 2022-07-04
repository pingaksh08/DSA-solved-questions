// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int n1 = m-l+1;
         int n2 = r-m;
         int temp1[n1] , temp2[n2];
         for(int i=0 ; i<n1 ; i++){
             temp1[i] = arr[l+i];
         }
         for(int i=0 ; i<n2 ; i++){
             temp2[i] = arr[m+1+i];
         }
         
         int i=0;
         int j=0;
         int k=l;
         while(i<n1 and j<n2){
             if(temp1[i] <= temp2[j]){
                 arr[k++] = temp1[i++];
             }
             else{
                 arr[k++] = temp2[j++];
             }
         }
         
         while(i<n1){
             arr[k++] = temp1[i++];
         }
         
         while(j<n2){
             arr[k++] = temp2[j++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l < r){
           int mid = l + (r - l)/2;
           mergeSort(arr , l , mid);
           mergeSort(arr , mid+1 , r);
           merge(arr , l , mid , r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends