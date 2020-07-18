//problem link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning/0
//GIVES TLE, OPTIMISED A LOT....STILL

#include<bits/stdc++.h>
using namespace std;
//if we declare here, any function can access it
int static dp[1001][1001];
bool ispalindrome(string str,int i,int j)
{
    if(i>=j)
        return true;
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    //here we
    return true;

}
int palindrome(string str,int i,int j)
{
    if(i>=j)
       return dp[i][j]=0;
    else if(dp[i][j]!=-1)
       return dp[i][j];
    else if(ispalindrome(str,i,j))
       return dp[i][j]=0;
    //j-1 as if k=j, then two partitions are i to k & k+1 to j so k+1 to j
    //will be an empty string i.e. an invalid input
    int minimum=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int left,right;
        //The below two if else conditions are for optimising top down
        //approach. Like we check for dp[i][j], if it is -1 or not
        //We will also check for dp[i][k] or dp[k+1][j]
        if(dp[i][k]!=-1)
            left=dp[i][k];
        else
        {
           left=palindrome(str,i,k);
           dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
        else
        {
            right=palindrome(str,k+1,j);
            dp[k+1][j]=right;
        }
        int tempans=left+right+1;
        minimum=min(minimum,tempans);

    }

    return dp[i][j]=minimum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int m=0;
        int n=str.length()-1;
        memset(dp,-1,sizeof(dp));
        cout<<palindrome(str,m,n)<<endl;
    }
	//code
	return 0;
}
