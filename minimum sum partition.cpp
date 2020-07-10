//problem link:-https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

//It is a variation of subset sum problem
//We just have to built a mathematical concept i.e:
//This problem aims at minimizing (S1-S2)
//And, S1 is none other than arr[sum]-S2
//So, the above expression reduces to (arr[sum]-2*S2)
//Now, arr[sum] is constant, so we have to just maximize the value of S2
//so that we subtract maximum from arr[sum] and minimize th whole expression
//But, S2 should be less than arr[sum]/2 to prevent the negative value, we suppose S2<S1
//If S2 is equal to arr[sum]/2, it will give 0 and increasing the value will
//further deviate from the result i.e. the value of expression increases from 0,1,2 ..& so on.
//We just push every element of last row of our t matrix in a vector vec & then find most suited value of S2
#include<bits/stdc++.h>
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
        int arr[n+1],sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        bool t[n+1][sum+1]={false};
        vector<int>vec;
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
                else if(arr[i-1]<=j)
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
                if(i==n&&t[i][j]==true&&j<=sum/2)
                {
                    vec.push_back(j);
                }

            }
        }
       int maximum=*max_element(vec.begin(),vec.end());
       cout<<sum-(2*maximum)<<endl;
    }
	return 0;
}
