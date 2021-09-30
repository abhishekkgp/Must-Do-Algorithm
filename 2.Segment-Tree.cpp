Leetcode Problem link: https://leetcode.com/problems/range-sum-query-mutable/

Problem Statement:
Given an integer array nums, handle multiple queries of the following types:
  Update the value of an element in nums.
  Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:
  NumArray(int[] nums) Initializes the object with the integer array nums.
  void update(int index, int val) Updates the value of nums[index] to be val.
  int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Time complexity: max(O(N), O(UlogN), O(QlogN) )    [ O(N) for constrution tree] and Ulog(N) [for each update where U nu,ber of update called], and
                                                   [O(QlogN) for Q number of sum range query] 
                                                   ->As all query(sum) and update will taek logN time.
Space complexity: O(N)   [for storing tree elements]
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Method-1: Using Segment Tree Recurssive

class NumArray {
    vector<int> tree;
    vector<int> a;
public:
   
    void constructTree(int index , int left_range , int right_range)        // index is responsible for the range "range_left" , "range_right" 
    {
        if(left_range > right_range)    return ;                                    // completely excluded region
        if(left_range == right_range)   { tree[index] = a[left_range]; return; };   // leaf node
        
        int mid = (left_range + right_range)/2;                                     // divide and conquer 
        constructTree(index*2+1 ,  left_range , mid);
        constructTree(index*2+2, mid+1 , right_range);
        tree[index] = tree[index*2+1] + tree[index*2+2];                              // store answer in this node
    }    
    // index = node's index , update_left/right is the range ehich need sto be updated , node_left/right means this node is responsible for these range
    void updater(int index, int update_left , int update_right, int node_left , int node_right, int val) 
    {
        if(update_left > node_right || update_right < node_left)    return;     // completely excluded
        if(node_left == node_right)                                             // reached leaf node 
        { 
            tree[index] = val; 
            a[node_left] = val;         // this line can be skipped, we dont give a fuck to vector a once tree has been made
            return; 
        };
        int mid = (node_left + node_right)/2;                                       
        updater(index*2+1 , update_left , update_right , node_left , mid       , val);
        updater(index*2+2,update_left , update_right , mid+1     , node_right, val);
        tree[index] = tree[index*2+1] + tree[index*2+2];
        return;
    }
    int get_sum(int index , int left_range, int right_range , int node_left , int node_right)       
    {
        if(left_range > node_right || right_range < node_left)  return 0;
        if(left_range <= node_left and right_range >= node_right)   return tree[index];
        
        int mid = (node_left + node_right)/2;
        int left_ans  = get_sum( index*2+1 , left_range , right_range , node_left , mid);
        int right_ans = get_sum(index*2+2, left_range , right_range , mid+1 , node_right);
        return left_ans + right_ans;        
    }
    
    // Below function are given function
    NumArray(vector<int>& arr) 
    {
        int n = arr.size(); 
        int x=ceil(log2(n)), max_size=pow(2,x);
        tree = vector<int> (2*max_size+1); // think of yourself here
        a = vector<int>(arr.begin() , arr.end());                               // note this step ,  we have created a global array , for our code, this step can be avoided , if we pass input array to this function, but to keep code simple we have made a global array
        constructTree(0,0,n-1);     // index, node_left , node_right
        
        // for(int i=0 ; i<=7  ; i++)            printf("i = %d\t\tvAL = %d\n", i, tree[i]);
    }
    void update(int i, int val) {
        updater(0,i,i,0,a.size()-1 , val);                                      // node the update_left/right are same, as these are point updates, 
    }
    int sumRange(int left_range, int right_range) {
        return get_sum(0 , left_range , right_range , 0 , a.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */



==========================================================================================================================================================
//Method-2
  
  
  
  
