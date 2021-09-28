We have an array A[0 . . . n-1] of size n. We can implement below to opration as many times as we want:
1 Compute the sum of the first i elements, for all i=0 to n-1. 
2 Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1. Then Compute the sum of the first i elements.

Solution:
Using Binary Index Tree, update(modifying) and getSum(sum till first ith element) can be done using O(logn) time.

Time complexity: O(nlogn)       [If we want to insert n elemnt then it will take total O(nlogn) time to insert/update all. 
                                If we want to update value of m elements then it will take total O(mlogn) time. where m<=n.]
Space complexity: O(n)         [ in storing BITree array]
  
Note: 
  1. Each a) update  b)getSum till ith element --> takes only log(n) time here. 
  2. Using brute force(without Binary index tree) inserting each updating sum takes O(n) time. so updating m elements takes O(mn) time. [Think]
     
------------------------------------------------------------------------------------------------------------------------------------------------------
// C++ code to demonstrate operations of Binary Index Tree
#include<bits/stdc++.h>
using namespace std;

/*		 
n --> No. of elements present in input array.
BITree[0..n] --> 1-based Array that represents Binary Indexed Tree.
arr[0..n-1] --> 0-based Input array for which prefix sum is evaluated. 
*/

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
void update(vector<int> &BITree, int index, int val) 
{
    while(index<BITree.size())
    {
        BITree[index]+=val;
        index+=index&-index;
    }
}

// Driver program to test above functions
int main()
{
	int A[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(A)/sizeof(A[0]);
	
	vector<int> BITree(n+1,0);
  for(int i=0;i<n;i++)
  {
      update(BITree,i+1,A[i]); //In i+1, adding 1 because BITree is 1 based index
  }
	cout << "Sum of elements in arr[0..5] is: "<< getSum(BITree, 6); 
	// In above 5+1 adding 1 because BITree is 1 based index

	// Let use test the update operation
	A[3] += 6;
	update(BITree, 3, 6); //Update BIT for above change in A[]
	cout << "\nSum of elements in arr[0..5] after update is: " << getSum(BITree, 5+1);

	return 0;
}

/*
# output:
Sum of elements in arr[0..5] is: 12
Sum of elements in arr[0..5] after update is: 18
*/
