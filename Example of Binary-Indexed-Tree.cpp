Problem Link: https://leetcode.com/problems/create-sorted-array-through-instructions/ 

Given an integer array A of instructions, you are asked to create a sorted array from the elements in A. 
You start with an empty container nums. For each element from left to right in A, insert it into nums. 

The cost of each insertion is the minimum of the following:
  The number of elements currently in nums that are strictly less than A[i].
  The number of elements currently in nums that are strictly greater than A[i].
  
For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) 
(elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7.

Solution Approch:  I used Binary Indexed Tree (or Fenwick Tree) to solve this problem.
 
 Time complexity: "O(nlogn)"                                 [where logn for each update and getSum and we are doing over n element so overall O(nlogn)]
  Space complexity: "O(1e5+1) | but we can also say O(m)"    [where m=1e5+1 or max value of all element present in A in this case]

-------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    
    // Returns sum of arr[0..index]. This function assumes that the array is preprocessed and 
    // partial sums of array elements are stored in BITree[].
    int getSum(vector<int> &BITree, int index)
    {
        int sum=0;
        while(index>0)
        {
            sum+=BITree[index];
            index-=index&-index;
        }
        return sum;
    }
    
    // Updates a node in Binary Index Tree (BITree) at given index in BITree. 
    // The given value 'val' is added to BITree[i] and all of its ancestors in tree.
    void update(vector<int> &BITree, int index, int val) // updating all 
    {
        while(index<BITree.size())
        {
            BITree[index]+=val;
            index+=index&-index;
        }
    }
    
    int createSortedArray(vector<int>& A) { // given function as input in problem
        int M=1e9+7;
        vector<int> BITree(100001, 0); //Binary tree 
        vector<int> fre(100001, 0); // counting frequency of each element at given point
        
        int cost=0;
        for(int i=0;i<A.size();i++)
        {
            // using Binary tree getSun(ie, query)   
            int left=getSum(BITree, A[i]-1);
            int right=i-left-fre[A[i]];
            
            cost=(cost%M +min(left,right)%M)%M ; //adding cost as per our problem statement
            update(BITree,A[i],1); // Indecring value of each index from A[i]th onward by 1
            fre[A[i]]++; // incresing current elemnt frequency
        }
        return cost;
    }
};
