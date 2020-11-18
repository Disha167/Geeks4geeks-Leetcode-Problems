 //to generate all boring numbers between range l and r
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void print(ll tc){
    cout<<"Case #"<<tc<<": ";
}
ll dp[20][2],bro[20];
ll func(string s,ll pos,bool flg){

    if(pos==s.size())return 1;
    if(dp[pos][flg]!=-1)return dp[pos][flg];
    ll & ans = dp[pos][flg];
    ans = 0;

    if(pos%2==0){
        for(ll i=1;i<=9;i+=2){
            if(flg)ans+=func(s,pos+1,flg);
            else{
                if(i<(s[pos]-'0'))ans+=func(s,pos+1,1);
                else if(i==(s[pos]-'0'))ans+=func(s,pos+1,0);
            }
        }
    }
    else{
        for(ll i=0;i<=9;i+=2){
            if(flg)ans+=func(s,pos+1,flg);
            else{
                if(i<(s[pos]-'0'))ans+=func(s,pos+1,1);
                else if(i==(s[pos]-'0'))ans+=func(s,pos+1,0);
            }
        }
    }

    return ans;
}
ll power(ll n,ll p){
    return bro[p];
}
void solve(ll tc){
    ll l,r;cin>>l>>r;

    string s = to_string(r);
    memset(dp,-1,sizeof(dp));
    ll v1 = func(s,0,0);
    int sz = s.size() - 1;
    if(sz)v1+=power(5,sz);

    memset(dp,-1,sizeof(dp));
    s = to_string(l-1);
    ll v2 = func(s,0,0);
    sz = s.size()-1;
    if(sz)v2+=power(5,sz);
    print(tc);
    cout<<v1-v2<<"\n";
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bro[0]=1;
    for(ll i=1;i<20;i++)bro[i]=bro[i-1]*5;
    bro[0]=0;
    for(ll i=1;i<20;i++)bro[i]+=bro[i-1];

    ll t;cin>>t;
    for(ll i=1;i<=t;i++)solve(i);
}


