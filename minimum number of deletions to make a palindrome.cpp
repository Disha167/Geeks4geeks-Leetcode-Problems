//For the input aebcbda, the output is 2 i.e.
//String is aebcbda & it's reverse is adbcbea & the LCS of the two strings
//are:
//1st String##$$$$$$||aebcbda||$$$$$$$$$$###########
//2nd String##$$$$$$||adbcbea||$$$$$$$$$$###########
//THEIR LCS###$$$$$$||abcba||$$$$$$$$$$$$###########
//We just need to subtract ed from the string aebcbda to get abcba i.eLPS
//So, minimum no. of deletions is 2 i.e. e & d
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1;
        cin>>str1;
        //JUST THE BELOW LINE CHANGES FROM PREVIOUS LCS QUESTIONS
        //use of reverse iterator to store the reversed string
        string str2=string(str1.rbegin(),str1.rend());
        cout<<str2<<endl;
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
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<len1-dp[len1][len2] <<endl;
    }
	return 0;
}
