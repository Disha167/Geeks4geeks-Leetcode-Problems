//Topological sort can only occur in a graph without cycle as in cycle, the meaning of dependency gets lost
//Topological sort is the ordering of the nodes such that if there is an edge from u->v so u should come before b in that order.
//The approach while using dfs traversal is that to make sure before pushing the node in the vector, that all it's children that are dependent on him goes so that
//on reversing the vector we get the corect order.
class Solution
{
    void dfs_topo(int source, vector<int> adj[], vector<int>&visited,vector<int>&ans)
	{
	    visited[source]=1;
	    for(auto x:adj[source])
	    {
	        if(!visited[x])
	        {
	            dfs_topo(x,adj,visited,ans);
	        }
	    }
      //we push the node into vector if it has no child i.e. no dependency that should be pushed before him in vector that will on reversing come after it in the ans.
	    ans.push_back(source);
	    
	}
	public:
	//Function to return list containing vertices in Topological order. 
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V+1,0); //V=6
	    vector<int>ans; 
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i]) 
	           dfs_topo(i,adj,visited,ans);
	    }
	    reverse(ans.begin(),ans.end());
	   
	    return ans;
	    // code here
	}
};
