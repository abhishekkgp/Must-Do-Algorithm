#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1, r=2*i+2;
    //for max heapify case
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest); // to heapify effected subtree
    }
    
}


void Build_maxheap(int arr[],int n)
{
	
    for(int i=n/2-1;i>=0;i--) // build heap
    {
        heapify(arr,n,i);
    }
    
    for(int i=n-1;i>0;i--)// max hepifing
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    
}


int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	Build_maxheap(arr,n);
	
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	
	return 0;
}
