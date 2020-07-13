//problem link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
//MEMOIZATION/TOP-DOWN CODE FOR LCS
#include<bits/stdc++.h>
using namespace std;
//we make the matrix global to omit the tiresome process of passing the dp
//matrix in every recursion call
int static dp[101][101];
int LCS(string str1,string str2,int len1,int len2)
{
    if(len1==0||len2==0)
        return 0;
    //***JUST ADD THE BELOW TWO LINES IN RECURSIVE CODE***
    if(dp[len1][len2]!=-1)
        return dp[len1][len2];
    if(str1[len1-1]==str2[len2-1])
        //if the character in two strings are same like in abcd,afgd,
        //the nth and mth character are same.
        //So, we reduce lengths of both strings by 1
        return dp[len1][len2]=1+LCS(str1,str2,len1-1,len2-1);

    else
        //if the characters are not same, there can be two cases
        //abcdf and abcgd i.e the n-2th and m-1th character are same
        //OR bnhem and bnhemr i.e.the n-1th and m-2th character are same
        //for making the common subsequence longer
        return dp[len1][len2]=max(LCS(str1,str2,len1-1,len2),LCS(str1,str2,len1,len2-1));

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int len1,len2;
        cin>>len1>>len2;
        string str1,str2;
        cin>>str1>>str2;
        memset(dp,-1,sizeof(dp));
        cout<<LCS(str1,str2,len1,len2)<<endl;

    }
	return 0;
}
