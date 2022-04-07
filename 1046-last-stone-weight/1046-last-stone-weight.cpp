class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*
            Approach -->
            will make max heap --> to keep max element on top
             we push all elements in priority queue then,
             continue this till the size of pq is 1 {
              put the top element in y then pq.pop() , then
              put the top element in x then pq.pop()
              Now, push their difference(y-x) back in pq 
             }
             return qp.top()
        */
        priority_queue<int , vector<int>> pq;
        for(int x : stones){
            pq.push(x);
        }
        
        if(pq.size() == 1)
            return pq.top();
        
        int x,y;
        while(pq.size() != 1){
          y = pq.top();
          pq.pop();
          x = pq.top();
          pq.pop();
          
          pq.push(y-x);
            
        }
        
        return pq.top();
    }
};