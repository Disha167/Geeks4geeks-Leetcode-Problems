//SIMILAR CONCEPT: HOUSE ROBBER Leetcode (Dynamic Programing)
//You have to return the minimum subsequence such that one integer among group of all 3 integers is picked. So, we used dynammic programming to calculate the minimum
//sum on including the current number and taking the minimum of dp[i-1],dp[i-2],dp[i-3] as if we will take dp[i-4], then a group of 3 consecutive integers will be
//left unpicked so condition will be violated
int solve(vector<int>& nums) {
    int dp[nums.size()+1];
    if(nums.empty())
    return 0;
    if(nums.size()==1)
    {
        return nums[0];
    }
    if(nums.size()==2)
    {
        return min(nums[0],nums[1]);
    }
    if(nums.size()==3)
    return min(nums[0],min(nums[1],nums[2]));
 
    dp[0]=nums[0];
    dp[1]=nums[1];
    dp[2]=nums[2];
    for(int i=3;i<nums.size();i++)
    {
        dp[i]=nums[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
    }
    int ans=INT_MAX;
  //IMP!!!!!!!!
  //At the end, you have to return minimum of dp[n-1],dp[n-2],dp[n-3] as in some cases, the minimum might not be the last window.
  //Eg for 1 2 3 4 5,
  //dp array is 1 2 3 5 7 and the minimum is dp[n-3] i.e. 3 is the answer not dp[n-1] i.e. 7
    ans=min(dp[nums.size()-1],min(dp[nums.size()-2],dp[nums.size()-3]));
    return ans;

    
}
