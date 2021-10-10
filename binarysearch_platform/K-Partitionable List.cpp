//We have tried all possible cases by recursion.
bool check(vector<int>&nums,vector<int>&visited, int k, int subset_sum, int curr_bucket_sum, int start_index)
{
  //if all the buckets are divided with subset_sum, the we return true;
    if(k==0)
        return true;
    //if the curr_bucket_sum becomes subset_sum, then we reduce k, and start filling another bucket starting from 0th index.
    if(curr_bucket_sum==subset_sum)
    {
 //IMP!!! We do not pass k by address, as if all the subsets cannot be made, then we have to backtrack and the current subset is not considered     
/*we have to return the func here as if k becomes 0 that means we have divided all the buckets, so it will return true to this func, & this func returns true to
main func solve*/        
        return check(nums,visited,k-1,subset_sum,0,0);
    }    
    for(int i=start_index;i<nums.size();i++)
    {
      //If the current number is not visited and adding it to current_bucket_sum will not exceed subset_sum, then we explore that possibility.
        if(!visited[i]&&nums[i]+curr_bucket_sum<=subset_sum)
        {
            visited[i]=1;
          //we pass i+1 as our next start_index as we are checking for all possible values and value of i is changing in every for loop.
            if(check(nums,visited,k,subset_sum,curr_bucket_sum+nums[i],i+1))
            return true;
            visited[i]=0;
        }
    }
  //if at the end, starting from a particular start_index, we cannot reach to the subset_sum by any means, then we return false;
    return false;
}
bool solve(vector<int>& nums, int k) {
    if(k>nums.size())
        return false;
    long total_sum=0;
    for(int i=0;i<nums.size();i++)
        total_sum+=nums[i];
    vector<int>visited(nums.size(),0);
    if(total_sum%k!=0)
    return false;
    int subset_sum=total_sum/k;
    int count=0;
    return check(nums,visited,k,subset_sum,0,0);
    // return true;
}
