class NumArray {
public:
    vector<int> op;
    int sum;
    
    NumArray(vector<int>& nums) {
      op = nums;
      sum=0;
      for(int i=0 ; i<nums.size() ; i++){
          sum += nums[i];
      }  
    }
    
    void update(int index, int val) {
       // changing the value in sum as well 
       sum -= op[index];
       op[index] = val;
       sum += val; 
    }
    
    int sumRange(int left, int right) {
        // remove all the elements before left and after right
        int ans = sum;
        for(int i=0 ; i<left ; i++){
            ans -= op[i];
        }
        for(int i=right+1 ; i<op.size() ; i++){
            ans -= op[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */