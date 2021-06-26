//USING BFS
//We have to check whether there is a cycle in graph i.e. we check that whether we can come across one node from two paths other than it's parent node
//EG:
//  1---2
//  |   |
//  3---4
//In this graph, 4 can be reached from 1->2->4 and also from 1->3->4 because there is a cycle and that is how we detect the cycle.And, we make sure to exclude the
//repetition of path i.e. 1-->2-->4 and then 4-->2-->1 and indicating cycle.. current parent are excluded.Here, 3 is not curr parent of 4 .. 2 was so we return true
//JUST MAKE SURE THAT THE ADJACENT NODE IS NOT PARENT FROM WHERE WE HAVE JUST CAME FROM!!
class Solution 
{
    public:
    bool bfs(vector<int>adj[], int V, int source,vector<int>&visited)
    {
     
        visited[source]=1;
        queue<pair<int,int>>q;
        q.push({source,-1});
        while(!q.empty())
        {
            pair<int,int>tp=q.front();
            q.pop();
            for(auto x:adj[tp.first])
            {
                if(visited[x]&&x!=tp.second) //to make sure x is not the parent node like in case of 1--2--3 graph, 2 is visited again as a adjacent of 3, but
                  //that dosen't mean the graph has cycle so the parents are excluded. Here, parent of 3 is 2 and x=2 so we don't return true.
                    return true;
                else if(!visited[x])
                {
                    q.push({x,tp.first});
                    visited[x]=1;
                }
                
            }
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
	        if(bfs(adj,V,i,visited))
	           return true;
	        }
	    }
	    return false;//if we have not found cycles for any components of graph
	    // Code here
	}
};
