//This question is extension of 2 SUM problem.
//We use here the approach of two pointer technique to find the pair that gives a particular sum in the array and hence reduce the complexity from O(n^4) to
//O(n^3). 
int solve(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int curr_diff=INT_MAX,min_abs_diff=INT_MAX;
    for(int i=0;i<nums.size()-1;i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
        int sum=nums[i]+nums[j];
        int start=0,end=nums.size()-1;
        while(start<nums.size()&&start<end)
        {
            if(start==i||start==j)
            {
            start++;
            continue;
            }
            if(end==i||end==j)
            {
            end--;
            continue;
            }
            int curr_sum=nums[start]+nums[end];
            curr_diff=min(curr_diff,abs(curr_sum-sum));
            if(curr_sum==sum)
                return 0;
            else if(nums[start]+nums[end]<sum)
                start++;
            else
                end--;    
        }
        min_abs_diff=min(min_abs_diff,curr_diff);
        }

    }
    return min_abs_diff;
}
