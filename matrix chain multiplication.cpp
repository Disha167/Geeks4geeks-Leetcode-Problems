//problem link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
//We don't have to find the result of multiplication, we just have to find
//the way to do the multiplication that gives minimum cost. It can be
//(A1A2)(A3A4) or A1(A2A3A4) or A1(A2A3)A4......
#include<bits/stdc++.h>
using namespace std;
int static dp[101][101];
int solve(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    else if(dp[i][j]!=-1)
        return dp[i][j];
    int minimum=INT_MAX;
    // k can not be equal to j because then while moving from k+1 to j,
    //it dosen't include any matrix dimensions
    //In array 1 2 3 4 5, if k=j then
    //i to k includes:
    //1*2 2*3 3*4 4*5
    //& k+1 to j includes nothing but the minimum size of the array has to
    //be 2 for making it a valid matrix dimension
    for(int k=i;k<=j-1;k++)
    {
        int tempans=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        minimum=min(tempans,minimum);
    }
    return dp[i][j]=minimum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
            cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        //i starts from left end & j starts from right end
        //i=0 is not valid as Ai=arr[i]*arr[i-1];
        int i=1;
        int j=size-1;
        cout<<solve(arr,i,j)<<endl;
    }
	//code
	return 0;
}
