//problem link: https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter/0
//COIN CHANGE PROBLEM UNBOUNDED KNAPSACK
//😭😭JUST TAKE CARE TO USE SEPERATE NAMES FOR FUNCTIONS & VARIABLES
#include<bits/stdc++.h>
using namespace std;
long long int dp[3][1000001];
void dp_calculate(int sum)
{
        int arr[3];
        arr[0]=1;
        arr[1]=2;

        for(int i=0;i<=2;i++)
        {
            for(long long int j=0;j<=sum;j++)
            {
                if(i==0&&j==0)
                    dp[i][j]=1;
                else if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
                else if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
                else
                     dp[i][j]=dp[i-1][j];
            }
        }
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int sum;
        cin>>sum;
        //😭😭 DON'T FORGET TO MEMSET AFTER EVERY TEST CASE to avoid
        //😈😈SEGMENTATION FAULT
        memset(dp,sizeof(dp),0);
        dp_calculate(sum);
        cout<<dp[2][sum]<<endl;
    }
    //code
	return 0;
}
