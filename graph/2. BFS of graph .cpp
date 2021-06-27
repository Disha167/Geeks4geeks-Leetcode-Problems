//There are two traversal techniques of graph: DFS & BFS . BFS means traversing level by level i.e. all the nodes at 1st level then all the nodes at 2nd level & so 
//on. We use queue for that as it allows access in order basis first in first out. Queue stores the source node, and while popping it out traverses all the adjacent 
//nodes of source & pushes it .Then one by one all nodes are popped treating it as source giving the breadth first traversal of graph.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>ans;
	    bool visited[V+1]={false};
	    queue<int>q;
	    q.push(0);
	    visited[0]=true;
	    while(!q.empty())
	    {
	        int tp=q.front();
	        ans.push_back(tp);
	        q.pop();
	        for(int j=0;j<adj[tp].size();j++)
	        {
	            if(!visited[adj[tp][j]])
	            {
	                visited[adj[tp][j]]=true;
	                q.push(adj[tp][j]);
	            }
	        }
	    }
	    return ans;
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

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
