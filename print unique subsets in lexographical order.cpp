//Mostly similar to printing all subsets of string problem in same repository just for lexographical order, enter all the subsets in a set
//And the input is in form of 1 2 2 , the character array has to taken input and concatenated to produce a string
//for more details of driver code, refer to problem: https://practice.geeksforgeeks.org/problems/subsets/0
#include<bits/stdc++.h>
using namespace std;
set <string > s1;
void subset(string ip, string op)
{
    if(ip.length()==0)
    {
        s1.insert(op);
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    subset(ip,op1);
    subset(ip,op2);
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char character_array[n+1];
        string ip="";
        for(int i=0;i<n;i++)
        {
            cin>>character_array[i];
            ip=ip+character_array[i];
        }
        string op="";
        subset(ip,op);
        for(auto it=s1.begin();it!=s1.end();it++)
        {
            op=*it;
            cout<<"(";
            for(int i=0;i<op.length();i++)
            {
               if(i==op.length()-1)
                 cout<<op[i];
               else
                 cout<<op[i]<<" ";
            }
            cout<<")";
        }
        cout<<endl;
    }
    	return 0;
}
