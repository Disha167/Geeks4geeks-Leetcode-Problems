//k goes upto 2^31 so O(N) solution is also not acceptable, so there is bound to be a pattern among the state of prison cell. On further observing, we found that
//it repeats after 14 days , so we % the number by 14 and then do the conversion constant number of times. Also, one corner case mentioned below needs to be considered
vector<int> solve(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>ans;
    vector<int>temp;
    temp=nums;
    ans=nums;
    while(k>14)
    {
    k=k%14;
    }
    cout<<k<<endl;
    k+=14;
    //we have to do this as sometimes when we have 1 in 
    //corners 1st and 14th are not same, i.e. it doesnt
    //repeat after 14 days . EG: 1 0 0 0 1 1 0 0
    //after 14 days gives 0 0 1 0 0  1 1 0 so we do 14
    //conversions at worst.
    while(k)
    {
        ans[0]=0; ans[n-1]=0;
        for(int i=1;i<=temp.size()-2;i++)
        {
            if(temp[i-1]==temp[i+1])
                ans[i]=1;
            else
                ans[i]=0;    
        }
        temp=ans;
        k--;
    }
    return ans;
}
