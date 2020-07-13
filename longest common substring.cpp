//problem link: https://practice.geeksforgeeks.org/problems/longest-common-substring/0
//Substring is just continous subsequence
//The code remains all same as that of longest common subsequence
//Just one change:
#include<bits/stdc++.h>
using namespace std;
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
        int dp[len1+1][len2+1];
        int maximum=INT_MIN;
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                if(i==0||j==0)
                   dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                //CHANGE FROM CODE OF LONGEST COMMON SUBSEQUENCE
                //Eg, we have two strings: abcdf and abcrt so on reaching
                //the 3rd character of both strings we have to make the
                //value of dp matrix cell as 0 as then another common
                //substring will start and continuity is lost
                    dp[i][j]=0;

                //& we calculate max length out of all cells
                maximum=max(maximum,dp[i][j]);
            }
        }
        cout<<maximum<<endl;
    }
	return 0;
}
