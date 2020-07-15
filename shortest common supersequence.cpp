//JUST ANOTHER VARIATION OF LCS
//Problem Link:  https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string str1,str2;
       cin>>str1>>str2;
       int len1=str1.length();
       int len2=str2.length();
       int dp[len1+1][len2+1];
       for(int i=0;i<=len1;i++)
       {
           for(int j=0;j<=len2;j++)
           {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    //if the characters are equal, then we call the
                    //recursive function of n-1 for both strings
                    dp[i][j]=1+dp[i-1][j-1];
                else
                   //if the characters on positions len1-1 & len2-1
                   //are not equal, then we take the maximum of i-1,j
                   //& i,j-1
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       int length_of_lcs=dp[len1][len2];
       //if the strings are let's say abcd and xycd, then they both
       //contain LCS so LCS is included twice so we add their length
       //& subtract LCS's length from them because we want it only once
       //in the supersequence
       cout<<len1+len2-(length_of_lcs)<<endl;
    }
	//code
	return 0;
}
