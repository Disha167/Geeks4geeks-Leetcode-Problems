///problem link:-https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
using namespace std;
//3D matrix for memoization as 3 variables change during recursion
//calls i, j and istrue
long long int dp[501][501][3];
int solve(string str,int i,int j,char istrue)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(istrue=='T')
            return str[i]=='T';
        else
            return str[i]=='F';
    }
    if(dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
    long long int ans=0,lt,lf,rt,rf,k;
    //k+2 as k is always partitioned or evaluated on a operator
    //k=i+1 as if the expression is T^F|F then k can only
    //start from i+1 i.e. 1 i.e. we can but brackets like (T)^(F|F)
    //but not ()T(^F|F)
    for(k=i+1;k<=j-1;k+=2)
    {
        if(dp[i][k-1]['T']!=-1)
            lt=dp[i][k-1]['T'];
        else
            lt=solve(str,i,k-1,'T');
        if(dp[i][k-1]['F']!=-1)
            lf=dp[i][k-1]['F'];
        else
        {
            lf=solve(str,i,k-1,'F');
        }
        if(dp[k+1][j]['T']!=-1)
            rt=dp[k+1][j]['T'];
        else
           rt=solve(str,k+1,j,'T');
        if(dp[k+1][j]['F']!=-1)
            rf=dp[k+1][j]['F'];
        else
            rf=solve(str,k+1,j,'F');
        if(str[k]=='&')
        {
            if(istrue=='T')
                ans+=lt*rt;
            else
                ans+=lt*rf+lf*rt+lf*rf;
        }
        else if(str[k]=='|')
        {
            if(istrue=='T')
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }
        else if(str[k]=='^')
        {
            if(istrue=='T')
                ans+=lt*rf+lf*rt;
            else
                ans+=lt*rt+lf*rf;
        }
    }
    dp[i][j][istrue]=ans%1003;
    return ans%1003;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        memset(dp,-1,sizeof(dp));

        //mp.clear();
        cout<<solve(str,0,n-1,'T')<<endl;
    }

	//code
	return 0;
}
