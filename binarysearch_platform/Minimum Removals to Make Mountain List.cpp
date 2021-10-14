/*
Mountain list is the sequence that is first strictly strictly increasing then strictly increasing, we have to find how many elements we have to remove from the 
array such that the remaining elements form the mountain list . We approach this problem by trying to remove the mountain list from the array as the length of
mountain list can be found but the length of elements to remove is unknown. We use nlogn LIS to find the lis ending at every index of the array, and for LDS , we
reverse the array and similarly find the LIS ending at every index of array. Then, when we have LIS of array & reverse array eg:
nums = [1, 6, 5, 7, 4]
numsRe=[4, 7, 5, 6, 1]
lis =  [1, 2, 2, 3, 3]
lisRev=[3, 3, 2, 2, 1]
Then the length of mountain list ending at 0 index will be lis ending at 0 and lis ending at 4th index i.e. 1 and 3 so we have 1 from strictly increasing and 4,5,6
from strictly decreasing i.e. 1,6,5,4 will be our mountain list. 

*/
vector<int> lis(vector<int>arr)
{
    set<int>seen;
    int index=0;
    vector<int>lis_res(arr.size(),0);
    for(int i=0;i<arr.size();i++)
    {
        auto it=seen.lower_bound(arr[i]);
        if(it==seen.end())
        {
            seen.insert(arr[i]);
        }
        else
        {
            seen.erase(it);
            seen.insert(arr[i]);
        } 
      //This is important , we have to keep on storing our lis so that we can calculate the mountain list at every index at the end.
        lis_res[index]=seen.size();
       
        index++;   
    }
    return lis_res;
}
int solve(vector<int>& nums) {
    /*
    1 6 5 7 4
    4 7 5 6 1
    */
    int n=nums.size();
    vector<int> nums_rev=nums;
    vector<int> lis_r(nums.size(),0);
    lis_r=lis(nums);

    reverse(nums_rev.begin(),nums_rev.end());
   vector<int> lis_l(nums.size(),0);
    lis_l=lis(nums_rev);

    int ans=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
       //Only if the length of subsequence will be greater than 1, then only it is valid. IMP!!!!
        if(lis_r[i]>1&&lis_l[n-i-1]>1)
        ans=min(ans,(int)(n-(lis_r[i]+lis_l[n-i-1]-1)));
    }
    return ans;
}
