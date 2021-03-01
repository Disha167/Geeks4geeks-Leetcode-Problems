//We use the trick that the weight Wi has to go from pos[Wi-1] to pos[Wi] i.e. hits=(pos[Wi-1]-pos[Wi]+1)/l[Wi] and so in pre-computation we take pos and l w.r.t to w[i] and
//not i.
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void tests() {

    int n;
    cin>>n;
    int w[n+1],pos[n+1],l[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        pos[w[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>l[w[i]];
    }
    int ans=0,hits;
    if(pos[2]<=pos[1])//if frog of weight 1 is ahead of frog of weight 2.
    {
        hits=ceil(float(pos[1]-pos[2]+1)/l[2]);
        ans+=hits;
        pos[2]+=hits*l[2];
    }
    if(n>2)
    {
     if(pos[3]<=pos[2])
    {
        hits=ceil(float(pos[2]-pos[3]+1)/l[3]);
        ans+=hits;
        pos[3]+=hits*l[3];
    }
    }
    if(n>3)
    {
    if(pos[4]<=pos[3])
    {
        hits=ceil(float(pos[3]-pos[4]+1)/l[4]);
        ans+=hits;
        pos[4]+=hits*l[4];
    }
    }
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
