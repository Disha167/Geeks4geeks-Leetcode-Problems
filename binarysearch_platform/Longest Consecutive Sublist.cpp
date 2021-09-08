//The approach is intuitive, we use the presence of every element from min to max range in consecutive sublist to our advantage. We calculate the prefix sum and 
//use minimum and maximum element for calculating whether this sublist is eligible. If all the elements are consecutive , then the sum of the sublist can be found
//out by calculating sum of first n numbers till max and subtracting sum of first n numbers till min from it. Eg for finding whether 4 7 6 5 is a consecutive sublist
//or not, we need to check whether it's sum is 7*(7+1)/2=28(if it is consecutive sublist, then all numbers till max should be present in it thus giving n*(n+1)/2 sum) 
//minus 3*(3+1)/2=6(all the numbers before min that are not there in list) 28-6=22
//We will follow n^2 approach of 2 pointers for checking all sublists and then prefix sum array and the above formula to constitute their sum and check whether it is
//eligible or not.
int solve(vector<int>& nums) {
    if(nums.empty())
        return 0;
    vector<int>presum(nums.size(),0);
    int sum=0,max_len=1;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        presum[i]=sum; 
    }
    for(int i=0;i<nums.size();i++)
    {
        int min_num=nums[i];
        int max_num=nums[i];
        for(int j=i+1;j<nums.size();j++)
        {
            min_num=min(min_num,nums[j]);
            max_num=max(max_num,nums[j]);
         
            if(i==0)
            {
                if(presum[j]==((max_num*(max_num+1)/2)-(min_num*(min_num-1)/2)))
                {
                    max_len=max(max_len,j-i+1);
                }

            }
            else
            {
                 if(presum[j]-presum[i-1]==((max_num*(max_num+1)/2)-(min_num*(min_num-1)/2))) //min_num*(min_num-1)/2 usage can be explained as same logic as presum[i-1]
                 {
                      max_len=max(max_len,j-i+1);
                 }
            }
        }
    }
    return max_len;
}
