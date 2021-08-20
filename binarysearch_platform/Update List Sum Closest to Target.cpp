//VARIATION OF PAINTER PARTITION PROBLEM
//For binary search, we need two things:
//1)A high and a low value i.e. a search space
//2)A factor to terminate half the search space while iterating
//We chose binary search as the value of sum is a monotonic increasing function of e i.e. on decreasing e, the value of sum decreases and on increasing e, value of sum of 
//array increases.
//Here, we do binary search on the value of e, i.e. we determine the search space of e and then on the basis of the difference of our current_sum and target , we move
//left and right in our search space i.e. if we get total sum of array less than target for e=3, it will be less for e=2, e=1... and so on, so we have to move to the
//right. And, if the total sum of array is already greater than our target for e=3, then we have to move to left as we have to answer the minimum value of e.
int sum_func(vector<int>nums,int mid, int&sum)
{
    sum=0;
    for(int i=0;i<nums.size();i++)
    {
       sum+=min(mid,nums[i]);
    }
    return sum;
}
int solve(vector<int>& nums, int target) {
    int sum=0;
    //we do binary search on value of e, as the sum of nums is a 
    //monotonically increasing function of e.
    int mx=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        mx=max(mx,nums[i]);
    }
    int start=0;
    int end=mx;
    int diff=INT_MAX;
    int ans=start;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int curr_sum=sum_func(nums,mid,sum);
        if(curr_sum>=target)
        {
            end=mid-1;
            
        }
        else
          start=mid+1;
        if(diff==abs(target-curr_sum)) //IMP: this is an edge case that we have to consider explicitly that if the absolute of target-currsum is less than diff, then we need
          //to update the ans but if it is equal to the difference, then we take minimum value of e on comparing
            ans=min(ans,mid);    
        else if(diff>abs(target-curr_sum)) 
        {
           ans=mid;
           diff=abs(target-curr_sum);
        }   
    }
    return ans;
}

