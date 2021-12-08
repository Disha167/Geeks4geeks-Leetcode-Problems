/*The main part is to analyse the question carefully & focus on the word exactly, we have to construct the binary string with exactly N hills & M valleys. So, when
the number of valleys & hills are equal, then the question is very simple eg. you have to generate a binary string with 4 hills & 4 valleys so we normally
keep on adding 0101010101 n+1 i.e. 5 times(length=10) and we get our ans as when we create 4 hills, consecutively 4 valleys are made.
So, when there is 1 difference between hills & valleys, i.e. 4 hills & 3 valleys then ans will be 010101010, we add 01 4 times n times and add a 0 for creating n 
hills and only n-1 valleys
But, the complex part comes when there is more than 1 difference between hills & valleys, if there are 4 hills and 2 valleys ,then we keep on adding 01,(4-1)3 times
then 001, (4-2)-1 times for avoiding the number of valleys to be increased further from 2. Hence our ans,   0101010010*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void tests() {

    int hills,valley;
    cin>>hills>>valley;
    int length=0;
    string s="";
    if(hills==valley+1)
    {
        length=(hills*2)+1;
        string str="01";
        for(int i=0;i<hills;i++)
        s+=str;
        
        s+="0";
        
    }
    
    else if(valley==hills+1)
    {
        length=(valley*2)+1;
        string str="10";
        for(int i=0;i<valley;i++)
        s+=str;
        
        s+="1";
    }
    
    else if(hills==valley)
    {
        length=(hills*2)+2;
        string str="01";
        for(int i=0;i<=hills;i++)
        {
            s+=str;
        }
    }
    
    else if(hills>valley)
    {
        length=2*(valley+1)+3*(hills-valley-1)+1;
        string str="01";
        for(int i=0;i<=valley;i++)
        {
            s+=str;
        }
        str="001";
        for(int i=0;i<hills-valley-1;i++)
        {
            s+=str;
        }
        s+="0";
        
    }
    
    else
    {
        length=2*(hills+1)+3*(valley-hills-1)+1;
        string str="10";
        for(int i=0;i<=hills;i++)
        {
            s+=str;
        }
        str="110";
        for(int i=0;i<valley-hills-1;i++)
        {
            s+=str;
        }
        s+="1";
         
    }
    
    cout<<length<<endl;
    cout<<s<<endl;
      

}
int32_t main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int t ;
	cin>>t;
	while(t--){
		tests();
	}
    return 0 ; 
}
