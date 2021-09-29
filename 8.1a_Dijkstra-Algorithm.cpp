Problem description:
    Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
    Note: The Graph doesn't contain any negative weight cycle.
  
 Time complexity: O(ELogV))     [as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V) ]
 Space complexity: "O(E+V)"    [as each edge will be included in priority_queue only once and also we are using distance vector of size V so space compalexity is O(E+V) ]             
---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}


// Prints shortest paths from src to all other vertices
void DijkstraShortestPath(vector<pair<int,int> > adj[], int V, int src)
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for (auto x : adj[u])
		{
			int v = x.first;
			int weight = x.second;
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main()
{
	int V = 9;
	vector<iPair > adj[V];

	// making above shown graph
	addEdge(adj, 0, 1, 4);
	addEdge(adj, 0, 7, 8);
	addEdge(adj, 1, 2, 8);
	addEdge(adj, 1, 7, 11);
	addEdge(adj, 2, 3, 7);
	addEdge(adj, 2, 8, 2);
	addEdge(adj, 2, 5, 4);
	addEdge(adj, 3, 4, 9);
	addEdge(adj, 3, 5, 14);
	addEdge(adj, 4, 5, 10);
	addEdge(adj, 5, 6, 2);
	addEdge(adj, 6, 7, 1);
	addEdge(adj, 6, 8, 6);
	addEdge(adj, 7, 8, 7);

	DijkstraShortestPath(adj, V, 0);

	return 0;
}


/*
OUTPUT:
       Vertex  Distance from Source
        0 		 0
        1 		 4
        2 		 12
        3 		 19
        4 		 21
        5 		 11
        6 		 9
        7 		 8
        8 		 14
*/
