//Problem link:- https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n>>w;
        int val[n+1],wt[n+1];
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        int t[n+1][w+1];
        memset(t,0,sizeof(t));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                if(i==0||j==0)
                     t[i][j]=0;
//**Don't forget to replace w by j in the line below as for every subproblem the weight is different
                else if(wt[i-1]<=j)
//All the code is same as knapsack 0 1, just one difference:
//If the element is included, it is not processed, it can be included
//any more no. of times, so we again call recursion for n instead of n-1
                      t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
                else
                      t[i][j]=t[i-1][j];
            }
        }
        cout<<t[n][w]<<endl;
    }
	return 0;
}
