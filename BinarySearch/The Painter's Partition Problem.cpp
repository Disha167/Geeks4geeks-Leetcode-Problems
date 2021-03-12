//Same as minimum allocation of pages, agressive cows etc.
//The aim of this question is to minimize the maximum time used by a single painter i.e. to make the job done at it's earliest as the painters would be working parallely on the
//jobs assigned to them. We use a number line for this method , here we put all the possible values of maximum time ranging from minimum time(i.e. the maximum in the board length
//array in order to optimize) to maximum time i.e. the sum of all arrays. We use binary search to iterate over the number line and check it's feasibility everytime i.e. whether 
//it can be assigned to k painters keeping in mind the current maximum time we have given i.e. our mid.  
//Eg: if arr[](board length): 10 20 30 40 and k(no of painters):2 
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool isvalid(int arr[], int n, int k, int mid)//We check the feasibility by assigning the work to one painter and when the work increases then mid, we
      //increase the no. of painters and begin assigning it to other painters
    {
        int painter=1,work=0;
        for(int i=0;i<n;i++)
        {
            work=work+arr[i];
            if(work>mid)
            {
                painter++;
                work=arr[i];
            }
            if(painter>k)//if the mid is 50 in the above given example then we assign 10 20 to student 1 (as if 30 assigned sum becomes 60>50), so we move to next painter assign
              //it 30 (40 cannot be assigned as 40+30=70 becomes greater than 60 i.e. not feasible) so we have to asssign 40 to third painter and painters becomes greater than
              //the given no. of painters i.e. 2 so we return false
            return false;
        }
        return true;
    }
    int find_min_time(int arr[],int n, int k)
    {
       
        int max_num=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            max_num=max(max_num,arr[i]);
            sum+=arr[i];
        }
        int start=max_num;
        int end=sum;
        int result=-1;
        while(start<=end)
        {
            int mid=start +(end-start)/2;
            if(isvalid(arr,n,k,mid))
            {
                result=mid;
                end=mid-1;//if it is valid, I optimise it further
            }
            else
            start=mid+1;//if not valid, we increase the capacity of 1
        }
        return result;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        cout<<ob.find_min_time(arr,n,k)<<endl;
    }
	//code
	return 0;
}
