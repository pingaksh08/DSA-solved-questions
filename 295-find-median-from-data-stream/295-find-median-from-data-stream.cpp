class MedianFinder {
public:
    // implement using two heaps(maxheap and minheap) and maintain them to equal size
    priority_queue<int> maxh;
    priority_queue<int , vector<int> , greater<int>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(maxh.empty() or maxh.top() > num)
          maxh.push(num);
      else
          minh.push(num);
        
       if(maxh.size() > minh.size() + 1){
           int val = maxh.top();
           minh.push(val);
           maxh.pop();
       }
        
       if(minh.size() > maxh.size() + 1){
           int val = minh.top();
           maxh.push(val);
           minh.pop();
       }
    }
    
    double findMedian() {
       if(maxh.size() > minh.size())
           return maxh.top()/1.0;
        
        if(minh.size() > maxh.size())
            return minh.top()/1.0;
        
        return (minh.top() + maxh.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */