class KthLargest {
public:
    /* we can use maxheap too but it will be difficult in returning answer in add fn, 
    thats why we are considering minheap */
    priority_queue<int , vector<int> , greater<int>> minheap;
    int size=0;
    
    KthLargest(int k, vector<int>& nums) {
       size=k;
        for(int i=0 ; i<nums.size() ; i++){
            minheap.push(nums[i]);
            
            if(minheap.size() > k)
                minheap.pop();
        }
    }
    
    int add(int val) {
       minheap.push(val);
       if(minheap.size() > size) minheap.pop();
        
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */