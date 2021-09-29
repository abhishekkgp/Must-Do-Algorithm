PROBLEM DESCRIPTION:
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

  You have to complete function "TopologicalSort" having V(number of vertex from 0 to V-1) and vector of array adj.
      adj[i] -> contains all the nodes which can be directed from node i. 

  You need to return array from "TopologicalSort" function in which array elements are in topological sort.
 

Time Complexity: O(V+E)  [as we are visting each verteces and edges once]
Auxiliary space: O(V)   [ as keeping track using visted vector to check either noed are visited or not]

-------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> TopologicalSort(int V, vector<int> adj[])  // function given as input to solve
	{
	    vector<int> visited(V,0); // checking nodes are visited or not
	    vector<int> ans;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0) find_order(ans,adj,vis,i);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
	
	void find_order(vector<int> &ans, vector<int> adj[], vector<int> &vis, int node) // being call in TopologicalSort funtion above
	{
	    if(vis[node]==1) return;
	    for(int x: adj[node])
	    {
	        if(vis[x]==0) getAns(ans,adj,vis,x);
	    }
	    
	    ans.push_back(node);
	    vis[node]=1;
	    return;
	}
};
