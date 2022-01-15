/*Question: Given an array nums, you need to find the maximum sum of triplet (nums[i] + nums[j] + nums[k]) such that 0 <= i < j < k and nums[i] < nums[j] < nums[k].
If no such triplet exists print 0.

This is a simple question but the conditon in the question nums[i]<nums[j]<nums[k] is very important , also 0<=i<j<k so the brute force would be O(n^3) i.e. for
every element we have to traverse the array , then fix the second element & traverse for the 3rd element. 

Another optimal approach is to iterate for the middle element & keep a record of left_max & right_max. The third element should be greater than the middle element
so storing the max_right by the suffix array will work, but the first element in the triplet should be smaller than the middle element so the previous larger
element i.e. prefix array method will not work here. We have to store all the elements till Ith index in a set and then traverse the set untill we find a element
smaller than the current middle element.

*/

#include <bits/stdc++.h>
using namespace std;

long long int maxSumTriplet(int n, vector<int> &nums){
    /*lowerbound && upperbound*/
    long long int ans=0;
    vector<int>max_right(nums.size(),0);
    multiset<int,greater<int>>max_left;
    for(int i=nums.size()-2;i>=0;i--)
    {
       max_right[i]=max(max_right[i+1],nums[i+1]);     
    }
    max_left.insert(nums[0]);
    for(int i=1;i<nums.size()-1;i++)
    {
        int curr_max_left;
        for(auto it=max_left.begin();it!=max_left.end();it++)
        {
            if(*it<nums[i])
            {
                curr_max_left=*it;
                break;
            }
        }
        long long int value=nums[i]+curr_max_left+max_right[i];
        if(curr_max_left<nums[i]&&nums[i]<max_right[i])/*This is important, if max_right is not greater than the current element then triplet is not valid*/
            ans=max(ans,value);
        max_left.insert(nums[i]);
    }
    return ans;
}

int main(){
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        long long int ans = maxSumTriplet(n, nums);
        cout << ans << endl;
    }
}

