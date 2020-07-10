//For problem statement, refer:https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

//using top down approach, with a little variation in knapsack dp code

//1)using or for true false instead of max
//2)ignoring the val array and using arr array instead of weight array and
//value of sum instead of weight
//3)Here, the value of sum is half of the total sum of array as we have to
//partition the array into 2 parts and so that suggests that the total sum
// of array should be even.
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        long sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        if(sum%2!=0)
            cout<<"NO"<<endl;
        else
        {
            sum=sum/2;
            bool t[n+1][sum+1];
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=sum;j++)
                {
                    if(i==0&&j==0)
                        t[i][j]=true;
                    else if(i==0)
                        t[i][j]=false;
                    else if(j==0)
                        t[i][j]=true;

                    else if(arr[i-1]<sum)
                        t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                    else
                        t[i][j]=t[i-1][j];
                }

            }
            if(t[n][sum]==true)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }
	return 0;
}

