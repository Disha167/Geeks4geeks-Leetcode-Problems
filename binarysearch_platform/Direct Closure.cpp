//In this question, we have been given the adjacency list of graph vector<vector<int>>& graph and we have to return a matrix adj of graph.size()*graph[i].size() with
//adj[i][j] marked as 1 if i has a path to j and adj[i][j] marked as 1, if i does not have a path to j then adj[i][j] is marked as 0.
//So, we have to find all the nodes that can be reached from each other and mark them 1, 1. In other words we have to find all the connected components.So, we use bfs to
//find all the connected nodes from each node and then store all the connected nodes in vector connected_components and mark all the pairs in the vector as 1 in adj.
void current_cc(int source, vector<int>&connected_components,vector<vector<int>>graph,vector<int>&visited)
{
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int tp=q.front();
        visited[tp]=1;
        q.pop();
        connected_components.push_back(tp); //we store all the nodes encountered while bfs as a part of our connected_components vector
        for(auto it:graph[tp])
        {
            if(visited[it]==0)
            {
                visited[it]=1;
                q.push(it);
            }    
        }
    }

}

vector<vector<int>> solve(vector<vector<int>>& graph) {
    vector<vector<int>> adj( graph.size() ,vector<int> (graph.size(), 0));
    vector<int>visited(graph.size(),0);
    vector<int>connected_components;
   for(int i=0;i<graph.size();i++)
   {
       adj[i][i]=1;
       if(visited[i]==0)
       {
           current_cc(i,connected_components,graph,visited);
         //After storing all the connected components, we mark all the pairs of the vector in adj list as 1.
           for(int i:connected_components)
           {
               for(int j:connected_components)
               {
                   adj[i][j]=1;
                   adj[j][i]=1;
               }
           }
           connected_components.clear();
       }
   }
    return adj;
}
