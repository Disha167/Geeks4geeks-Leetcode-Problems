//problem link: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
//The algorithm used below can also be used as a sorting algorithm for numbers from 1 to n
//The idea is to iterate through the array and place the element on the array on that position i.e. place 3 on 2nd position if 0 based indexing In this process of swaping
//3 on 2nd position,  the number that comes at the current position where 3 was may not be at the right place, so we do swapping while it is <1 >length or at correct position
// i.e. nums[i]!=nums[nums[i]-1]
//SPACE COMPLEXITY IS O(n) as we  perform 1 swap for each element at max to place it at right location i.e. (i-1)th location if number is i
using namespace std;
int firstMissingPositive(vector<int> &nums) {
        int length=nums.size();
        int i=0;
        
        for(;i<length;)
        {
        //we want positive integer so we take greater than 1 and < length as in worst case also if we have all integers from 1 to n, then smallest positive can become
        //n+1, it can't exceed that.And, we use while as for that particular position when we swap two nos, then one number comes in place i.e at (i+1)th and one number goes out
        //of place, the number present at the current memory location, so we have to swap untill it gets the right number
            while(nums[i]>=1&&nums[i]<=length&&nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }   
            i++;
        }
        for(i=0;i<length;i++)
        {
            if(i+1!=nums[i])
                return i+1;
        }
        
       return length+1; 
    }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<int>A;
        int arr[1000001];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            A.push_back(arr[i]);
        }
       cout<<firstMissingPositive(A)<<endl;
    }
    return 0;
}
