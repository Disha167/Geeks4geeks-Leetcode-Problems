//The approach is same as BFS detecting cycle process, while traversing if we encounter a particular node twice and if it is not a parent node then we say dfs has 
//cycle .
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    bool dfs(vector<int>adj[], int V, int source,vector<int>&visited, int parent)
    {
     
        visited[source]=1;
        for(auto x:adj[source])
        {
            if(!visited[x])
            {
                if(dfs(adj,V,x,visited,source)==true) //care that in every function call, x is made source & parent becomes source
                   return true;
                
            }
            else if(x!=parent) 
                return true;
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	   vector<int>visited(V+1,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	        if(dfs(adj,V,i,visited,-1))
	           return true;
	        }
	    }
	    return false;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
