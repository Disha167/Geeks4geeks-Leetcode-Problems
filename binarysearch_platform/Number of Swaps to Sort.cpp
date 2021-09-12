//The task here is that there is a series of unsorted numbers like 6 4 2 14 8 10 12 16 is given and we have to find the number of swaps to convert it to sorted order:
//So, we approach this in a reverse order: we store 6,0  4,1  2,2  14,3  8,4   10,5  12,6  16,7 in a vector and then sort it as:
//                                                  2,2  4,1  6,0  8,4   10,5  12,6  14,3  16,7
//now ,we try to convert the sorted array into the form in which it was given, now we know that 2,2 needs to go to 2nd index(0 based indexing) and that is the advantage!!
//We can either calculate it by naive method or also use disjoint set union  data structure for the same:
//UNION FIND APPROACH:
//2,2 needs to swap with 6,0 with forms an edge(cycle) in disjoint set union, again 4,1 is at correct index so we move forward. Now 8,4 needs to be at 4th index, at 4th index
//we have 10,5 which has to be at 5th index, at 5th index we have 12,6 that needs to be at 6th index , at 6th index we have 14,3 that needs to be at 3rd index thus
//forming a cycle, these all 8,4 10,5 12,6 14,3 forms a cycle and hence a connected component of DSU. 
//Now, we know that if connected components has k nodes it takes k-1 swaps to become sorted, eg above components 4 nodes and it takes 3 swaps, so the minimum
//number of swaps can be given by total elements-no of connected components(as 1 less size for all connected components and 1 for already sorted array that makes 1 
//connected component)
struct unionFind{
    int n;
    vector<int> parent,rank;
    unionFind(int n)
    {
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }
    int findpar(int node)
    {
        if(node==parent[node])
        return node;
        else
        return parent[node]=findpar(parent[node]);
    }

    void find_union(int u, int v)
    {
        u=findpar(u);
        v=findpar(v);
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
    }
};

int solve(vector<int>& nums) {
vector<pair<int,int>>vec;
for(int i=0;i<nums.size();i++)
{
    vec.push_back({nums[i],i});
}
sort(vec.begin(),vec.end());
unionFind obj(nums.size());
for(int i=0;i<nums.size();i++)
{
    obj.find_union(vec[i].second,i);
}
unordered_set<int>forbidden;
for(int i=0;i<nums.size();i++)
{
    forbidden.insert(obj.findpar(i));
}
return nums.size()-forbidden.size();
}
