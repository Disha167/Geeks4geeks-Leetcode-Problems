//Interesting ques based on sliding window technique
//The minimum cost for converting each one will be 1 atleast. We would aim on creating k consecutive zeros in the array to make the array like this 11000011 if k=4 then we can
//select one 1 at a time and take 3 zeroes to make it zero giving minimum cost 1 and similarly convert all ones to zeroes one by one. To create k consecutive zeros in the array
//optimally , we choose the minimum sum subarray of size k . To find minimum sum subarray, we use sliding window technique. 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void tests() {

    ll n,k;
    cin>>n>>k;
    ll arr[n+1],prefix_sum[n+3],total_ones=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
        total_ones++;
        
    }
    prefix_sum[0]=arr[0];
    for(ll i=1;i<n;i++)
    {
    
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
       // cout<<prefix_sum[i]<<" ";
    }
   // cout<<endl;
    ll min_prefix_sum=INT_MAX;
    for(ll i=0;i<=n-k;i++)
    {
       // cout<<i+k-1<<" "<<i<<" "<<prefix_sum[i+k-1]-prefix_sum[i]+arr[i]<<endl;
        min_prefix_sum=min(min_prefix_sum,(prefix_sum[i+k-1]-prefix_sum[i]+arr[i]));//checking all subarrays of size k starting from each index and finding minimum of them
    }
    ll ans=(total_ones-min_prefix_sum);//then the remaining ones will take all cost 1, and we convert whole array to 0
    ans+=((min_prefix_sum)*(min_prefix_sum+1)/2);
    cout<<ans<<endl;

}
int32_t main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int t = 1;
	cin>>t;
	while(t--){
		tests();
	}
    return 0 ; 
}
