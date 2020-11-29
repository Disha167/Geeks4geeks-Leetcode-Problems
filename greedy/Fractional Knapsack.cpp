//CODECHEF November Lunchtime Problem GASOLINE:https://www.codechef.com/LTIME90B/problems/GASOLINE
//How to identify that it is fractional knapsack?
//Your goal is to fill the cars in such a way that you are able to choose an optimal car, travel the clockwise distance N
//So, we have to distribute N litres optimally among all the cars i.e. requires least price so we sort them by price ratio(as here price of 1 item is given so price/weight not taken) 
//When we sort it dosen't means we have to start from the first car in the array like if our cost array is: 1 9 9 2 9 9 and fuel is 2 6 5 4 3 1
//After sorting, it becomes cost: 1 2 9 9 9 9 and fuel: 2 4 6 5 3 1
//So, our capacity is 6 as size of array is 6, so first we select 2 , cost becomes 2*1 and then select 4, total cost becomes 2+(4*2)=10
//Notice, here when we start from taking 2, we start from 1st car and we reach 3rd car, but 3rd car has no fuel.(as we have selected 1st and 2nd car)
//If we select 2nd first then we travel 2nd->3rd->4th->5th->6th, we reach 1st car take 2 litres of gasoline and then reach 4th car covering whole N
//distance, so order of car i.e. either we select 1st car first or 2nd car first is not decided by the sorted array

//USING FRACTIONAL KNAPSACK, WE JUST DIVIDE THE FUEL CORRECTLY
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
/*bool mycmp(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    double r1=(double)a.first/a.second;
    double r2=(double)b.first/b.second;
    return r1<r2;
}*/
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,sum=0;
	    cin>>n;
	    ll fuel[n];
	    ll price[n];
	    for(ll i=0;i<n;i++)
	        cin>>fuel[i];
	    for(ll i=0;i<n;i++)
	        cin>>price[i];
	    vector<pair<ll,ll>>vec;
	    ll curr_cap=n;
	    for(ll i=0;i<n;i++)
	    {
	        vec.push_back(make_pair(price[i],fuel[i]));
	    }
	    sort(vec.begin(),vec.end());
	    ll result=0;
	    for(ll i=0;i<n;i++)
	    {
	        if(vec[i].second<=curr_cap)
	        {
	           curr_cap-=vec[i].second;
	           result+=(vec[i].second)*(vec[i].first);
	        }
	        else if(vec[i].second>curr_cap)
	        {
	            result+=((vec[i].first)*(curr_cap));
	            break;
	        }
	       if(curr_cap<=0)
	        break;
	    }
	    cout<<result<<endl;
	}
	return 0;
}

