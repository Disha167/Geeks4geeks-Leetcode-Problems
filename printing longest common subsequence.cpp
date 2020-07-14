//PLAY WITH THE DP MATRIX FORMED IN LCS TO PRINT THE LONGEST
//COMMON SUBSEQUENCE
//REFER TO THE IMAGE OF THE FILLED DP MATRIX IN THE SAME REPOSITORY

//MEMOIZATION/TOP-DOWN CODE FOR LCS
#include<bits/stdc++.h>
using namespace std;
//we make the matrix global to omit the tiresome process of passing the dp
//matrix in every recursion call
int static dp[101][101];
void LCS(string str1,string str2,int len1,int len2)
{
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
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int len1,len2;
        cin>>len1>>len2;
        int unchanged_len1=len1;
        int unchanged_len2=len2;
        string str1,str2;
        cin>>str1>>str2;
        LCS(str1,str2,len1,len2);
        string s="";
        for(int i=unchanged_len1;i>=1;)
        {
            for(int j=unchanged_len2;j>=1;)
            {
                //IF THE CHARACTERS OF BOTH STRINGS ARE SAME, THEN IT HAS
                //COME FROM THE DIAGONALLY ABOVE CELL i.e. i-1 & j-1
                if(str1[i-1]==str2[j-1])
                {
                    s.push_back(str1[i-1]);
                    i--;
                    j--;
                }

                //IF THE CHARACTERS OF THE STRING ARE DIFFERENT,THEN WE
                //COMPARE THE TWO CELLS i-1,j and i,j-1
                //& WE TRAVERSE BACKWARD TO THE ONE HAVING THE LARGEST VALUE,
                //BCOZ THAT IS WHERE WE CAME FROM WHILE FILLING THE DP TABLE
                else
                {
                    if(dp[i-1][j]>dp[i][j-1])
                        i--;
                    else
                        j--;
                }
            }
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
	return 0;
}
