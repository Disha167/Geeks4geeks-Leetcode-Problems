//problem link:https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
//using LCS of original array & increasing sorted order
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>A;
        vector<int>B;
        string str1,str2;
        unordered_set<int>s;

        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            A.push_back(x);
            B.push_back(x);
        }
        sort(A.begin(),A.end());
        vector<int>::iterator ip;
        ip = unique(A.begin(), A.begin() + A.size());
        // Now v becomes {1 2 3 7 8 10 * * * * * *}
        // * means undefined
        // Resizing the vector so as to remove the undefined terms

        A.resize(distance(A.begin(), ip));
        n=A.size();
        int m=B.size();
        int dp[n+1][m+1]={0};
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(A[i-1]==B[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[n][m]<<endl;
    }
	//code
	return 0;
}
