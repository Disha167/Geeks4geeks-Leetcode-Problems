/*
It is very easy problem, the approach is to form an array nums+nums and then run a sliding window of size n and find the lis for each sliding window (as it can be
circular LIS). At, the end we return the maximum LIS of all.

HOW TO CALCULATE LIS:
The observation is, when we encounter new smallest element in the array, it can be a potential candidate to start new sequence.

Also, ensure we have maintained the condition, “end element of smaller list is smaller than end elements of larger lists“.
*/
int lis(vector<int>&arr,int start,int end)
{
    set<int>seen;
    for(int i=start;i<=end;i++)
    {
      //Lower_bound gives first element in the set whose value is not less than arr[i].
        auto it=seen.lower_bound(arr[i]);
        if(it==seen.end())
            seen.insert(arr[i]);

        else
        {
            seen.erase(it);
            seen.insert(arr[i]);
        }  

    }
    return seen.size();
}
int solve(vector<int>& nums) {
    vector<int>arr=nums;
    //Maintain a sliding window of size n
    int start=0,end=nums.size()-1;
    int ans=lis(nums,start,end);
    for(int i=0;i<nums.size();i++)
    {
        arr.push_back(nums[i]);
        start++;
        end++;
        ans=max(ans,lis(arr,start,end));
    }
    return ans;
}
