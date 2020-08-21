//Problem link: https://practice.geeksforgeeks.org/problems/count-number-of-hops/0/
//THIS IS A SIMPLE PROBLEM OF DP
//DIFFERENCE FROM COIN CHAGE IS:🧐🧐
//In coin change, we consider 1 2 1 , 1 1 2 and 2 1 1 all same,
//but here we have to count 3 for all the above cases seperately.
//Explaination😋😋
//For counting the number of hops for 4, we add all the possible hops
//for 3,2,1 we have 3 hops for 3, 2 hops for 2, 1 hop for 1, so for 4 there
//are 3+2+1 7 hops
//Similarly, if we take 5, see in recursion tree made below, for going through 4
//we can take either path from 3, from 2 , from 1 so 7 paths from going through
//4 and rest we can also make 5 by 3+2, and ways of reaching 3 is 4 so now
//number of ways reaching 5 becomes 7+4 i.e 11
//Now, we can still go to 5 by 2+3 and ways of reaching 2 is 2, so ways of
//reaching 5 finally becomes 11+2=13ans.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int steps;
        cin>>steps;
        int dp[steps+1];
        //We need to start for loop from 3 and declare rest of dp values
        //exclusively to avoid negative indexing error
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        if(steps==1||steps==2)
            cout<<steps<<endl;
        else
        {

            for(int i=3;i<=steps;i++)
            {
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            }
            cout<<dp[steps]<<endl;
        }
    }
}
