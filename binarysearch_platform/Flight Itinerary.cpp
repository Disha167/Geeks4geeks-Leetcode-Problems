//This question can be solved by conventional topological sort as it is just asking the airports visited in correct order but the topologcial sort of strings
//is hard to implement  at first. The graph gives error!!! be made by using conventional vector<vector<string>>adj rather map<string,multiset<string>>adj, multiset 
//because the destination can be dublicate .

vector<string> solve(vector<vector<string>>& flights) {
    unordered_map<string,multiset<string>>adj;
    unordered_map<string,int>indegree;
    for(int i=0;i<flights.size();i++)
    {
        adj[flights[i][0]].insert(flights[i][1]);
        indegree[flights[i][1]]++;
    }
    queue<string>q;
    unordered_map<string,int>visited; //everywhere map<string,int> is used as we have to do mp["A"]++, that cannot be done with vector of strings.
    vector<string>ans;
    for(int i=0;i<flights.size();i++)
    {
        if(indegree[flights[i][0]]==0)
        {
           q.push(flights[i][0]);
           ans.push_back(flights[i][0]);
           visited[flights[i][0]]=1;
        }
        if(indegree[flights[i][1]]==0)
        {
            q.push(flights[i][1]);
            ans.push_back(flights[i][1]);
            visited[flights[i][1]]=1;
        }   
    }
    while(!q.empty())
    {
        string tp=q.front();
        q.pop();
        for(auto it:adj[tp])
        {
            if(visited[it]==0)
            {
                indegree[it]--;
            }
            if(indegree[it]==0)// as soon as we get a node with indegree 0 i.e. no dependency, we push it back in the queue i.e. topological sort is done
            {
                q.push(it);
                ans.push_back(it);
            }
        }
    }
    return ans;

}
