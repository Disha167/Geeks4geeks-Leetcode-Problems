//AGAIN A VARIATION OF LCS
//problem link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0

#include<iostream>
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
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                if(i==0||j==0)
                    //if any of the strings are empty, then there is
                    //nothing common between them
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }
        int length_of_lcs=dp[len1][len2];
        //no. of deletions: len1-length_of_lcs i.e delete hp heap-ea=hp
        //so, we delete hp from heap and it becomes ea i.e. LCS
        //no. of insertions:len2-length_of_lcs i.e insert p ea+p=pea
        cout<<(len1-length_of_lcs)+(len2-length_of_lcs)<<endl;
    }
	//code
	return 0;
}
