
INPUT FORMAT: 
    The first argument given is an integer n representing the number of nodes in the graph.

    The second argument given a matrix edges of size M x 3 which represents the M edges such that 
    there is a edge between node edges[i][0] and node edges[i][1] having weight edges[i][2].

Output Format:
    Return Minimum Weight/Cost Spanning tree.
        
Time complexity: " O(ElogE) or O(ElogV)"  [as Sorting of edges takes O(ELogE) time & iterating all edges and find union take O(ELogV).]
                  (overall complexity is O(ELogE + ELogV) time but the value of E can be at most O(V2), so O(LogV) & O(LogE) are same. 
                   So, overall time complexity is O(ElogE) or O(ElogV))
space complexity: "O(V)"    [ as we are using two vector array to store parent and rank of each node so both are taking O(V) space]
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool compare( const vector<int>& a, const vector<int>& b ) 
{
  return a[2] < b[2]; //sorting according to 3rd column elements
}

int find_parent(int u, vector<int> &parent)
{
    if(u==parent[u]) return u;
    return parent[u]=find_parent(parent[u],parent);
}

bool union_set(int u, int v, vector<int> &rank, vector<int> &parent)
{
   int i = find_parent(u), j = find_parent(v);
   if(i != j) //cycle is not formed
   { 
      if(rank[u]>rank[v])
      {
          parent[v]=u;
      }
      else if(rank[u]<rank[v])
      {
          parent[u]=v;
      }
      else
      {
          parent[u]=v;
          rank[v]++;
      }

      return true;
   }
   return false; // cycle is formed
}



int kruskal((int n, vector<vector<int> > &edges){
    int MST = 0, e=edges.size(), k=1;
    vector<int> rank(n,0);
    vector<int> parent(n);
    for(int i=1;i<n;i++)
    {
        parent[i]=i;
    }
    
    sort(edges.begin(), edges.end(), compare);
    
    // we are tracking k<n as final number of edges should not be more than n-1 (where n is no. of vertices)
    for(int i = 0; i < e && k < n ; i++) 
    {
        int wt = edges[i][2];
        int u = edges[i][0], v = edges[i][1];

        if(union_set(u ,v ,rank ,parent)) // Returns true if joining v and v wull not form cycle
        {
            MST += wt;
            k++; 
        }
    }
    
    return MST;
}
