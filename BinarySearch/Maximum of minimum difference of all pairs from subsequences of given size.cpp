// Maximum of minimum difference of all pairs from subsequences of given size
//Painter Partition Problem Variation
#include <bits/stdc++.h>
using namespace std;
bool isplace(int mid, int B, vector<int> &A)
{
    int n=A.size();
    int last_num=A[0];
    int size_of_valid_subsequence=1;
    /*We calculate here that whether there is a subsequence which has minimum pair
    difference as B*/
    for(int i=1;i<n;i++)
    {
        /*if the pairs have difference greater than mid, it is acceptable but not less than
        mid. For less than mid, minimum difference will be changed*/
        if(A[i]-last_num>=mid)
        {
            last_num=A[i];
            size_of_valid_subsequence++;
            if(size_of_valid_subsequence==B)/*if the count is B, then mid is our valid 
                                             answer*/
            return true;
            
        }
    }
    return false;
}
int find_min_difference(vector<int> A, int B)
{
    int arr_size=A.size();
    int start=0;/*diff can be minimum 0*/
    int end=A[arr_size-1]-A[0];/*largest it can be diff of */
    int ans=INT_MIN;
    while(start<=end)
    {
        int mid=start + (end-start)/2;
        if(isplace(mid,B,A))/*if mid is a valid answer then we go on increasing the mid
        as we want the maximum of all minimums*/
        {
            ans=max(ans,mid);
            start=mid+1;
        }
        else /*if it is not valid, we lower the bar.*/
        end=mid-1;
    }
    return ans;
}
int main()
{
    vector<int> A = { 5, 17, 11 };
    int B = 2;
    int min_difference=find_min_difference(A,B);
    cout<<endl;
    cout<<min_difference<<endl;
    return 0;
    
}
