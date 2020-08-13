//problem link: https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string/0
#include<bits/stdc++.h>
using namespace std;
bool check(int i,string str)
{
    string str1, str2;
    for(int j=0;j<=i/2;j++)
        str1.push_back(str[j]);
    for(int j=i/2+1;j<=i;j++)
        str2.push_back(str[j]);
    if(str1==str2)
        return true;
    else
        return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int n=str.length();
        int dp[n+1]={0};
        for(int i=0;i<n;i++)
        {
            /*USE OF DP: In 1D array, we store the minimal no. of moves for ith index
            like in abcabca, minimal no. of moves at 0th index is 1 , 1st index is 2 & so on.*/
            //HERE DP COMES INTO PLAY: at 5th index of abcabca we require 4 moves,
            //i.e. no. of moves of dp[i/2]+1 as abc itself is entered again before
            //checking the condition that string from 0 to i/2 & i/2 +1 to i are equal
            if (check(i,str)==true)
                dp[i]=dp[i/2]+1;
            else
                dp[i]=dp[i-1]+1;
        }
        cout<<dp[n-1]<<endl;
    }
	//code
	return 0;
}
