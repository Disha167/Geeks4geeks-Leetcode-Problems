//This is a tricky question, it can be solved by considering all the testcases at worst, if we can convert atmost 3 integers to minimize the difference between 
//maximum element and minimum element of integer, then these 4 cases can arise:
//Convert first 3 elements to 4th element when sorted
//Convert last 3 elements to 4th element from last
//Convert first 2 elements to 3rd element and last element to 2nd last element
//Convert first element to 2nd element ans last two elements to 3rd last element
int solve(vector<int>& nums) {
    int n=nums.size();
    sort (nums.begin(),nums.end());
    int min_num=nums[0];
 
    int ans=INT_MAX;
    if(nums.size()<=3)
        return 0;
 
//All of the cases can be cleverly covered by updating the answer variable.
    ans=min(ans,nums[n-1]-nums[3]);
    ans=min(ans,nums[n-4]-nums[0]);
    ans=min(ans,nums[n-2]-nums[2]);
    ans=min(ans,nums[n-3]-nums[1]);

    return ans;



}
