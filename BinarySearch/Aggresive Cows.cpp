//Same approach as painter partition problem, just the barn array might not be sorted so we sort the barn first and here for checking feasibility , we try to place the cows in 
//the barn one by one and if it is feasible we move to the right side of array(for checking further chances of maximisation) and if not to left side
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
class Solution{
public:
ll feasible(ll barn[], ll n, ll c, ll mid)
{
	int cows=1;
	ll prev=barn[0];
	for(ll i=1;i<n;i++)
	{
		if((barn[i]-prev)>=mid)
		{
			prev=barn[i];
		cows++;
		}
		if(cows>=c)
		return true;
		
	}
	return false;
}
ll find_min_dis_bw_cows(ll barn[], ll n, ll c)
{
	ll start=1;
	ll end=barn[n-1];
	ll result=0;
	while(start<=end)
	{
	   ll mid=start + (end-start)/2;
	   if(feasible(barn,n,c,mid))
	   {
	   	   result=mid;
	   	   start=mid+1;
	   }
	   else
	   end=mid-1;
	}
	return result;
}
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		ll n,c;
		cin>>n>>c;
		ll barn[n+1];
		for(ll i=0;i<n;i++)
		cin>>barn[i];
		sort(barn,barn+n);
		Solution ob;
		cout<<ob.find_min_dis_bw_cows(barn,n,c)<<endl;
	}
	// your code goes here
	return 0;
}
