//Intresting question on dp concept, essentially what we are doing is either subtracting x-y i.e. y-x or adding x-y on later stages so we are essentially putting
//a  + or a - sign before every integer i.e. same as smallest subset sum difference problem.
int solve(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
    int dp[nums.size()+1][sum+1]={-1};
    for(int i=0;i<=nums.size();i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0&&j==0)
            dp[i][j]=1;
            else if(i==0)
            dp[i][j]=0;
            else if(j==0)
            dp[i][j]=1;
            else if(nums[i-1]<=j)
            dp[i][j]=dp[i-1][j]|dp[i-1][j-nums[i-1]];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    int min_val=INT_MAX;
    for(int j=0;j<=sum/2;j++)
    {
        if(dp[nums.size()][j])
        {
            min_val=min(min_val,sum-2*j);

        }
    }
    return min_val;
}
