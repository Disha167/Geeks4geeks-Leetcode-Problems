//It is an interesting problem that requires visualisation of dice, we have been asked for minimum visible surface area so we consider cuboid. So, frst we
//fill the current layer with four dice before moving on to next layer.The sum of 6 natural nos i..e 1,2,3,4,5,6 all the faces of dice that are ideally there is 21,
//but we have to count only those faces that are visible after our arrangement.
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll unsigned long long int

void tests() {

    ll n;
    cin>>n;
    ll rem=n%4; //we calculate the remainder as after placing the stacks of 4, the arrangement and so max. sum of pips for all 1,2,3 dices will be different.
    ll sum_of_6_natural_nos=21;
    ll ans=0;
    ll stacks_of_4=n/4; //to calculate ho many layers containing all 4 dice would be there
    if(n>=4)
    ans=(stacks_of_4*4*(6+5))+(4*4);//if we talk about 4 dice kept together, only 2 faces of each dice would be visible so we take them max. nos possible i.e. 5 and 6
  //and then add 4 times 4 only once for the topmost layer visible
    if(rem==1)
    {
        if(ans!=0)
        {
            ans-=4; //we subtract 4 once as one die kept over the stack of 4 dices will cover 1 dice's topmost surface.
        }
        ans+=(sum_of_6_natural_nos-1);//and while placing, the bottomost face of that die will also be covered so we subtract 1.
    }
    else if(rem==2)
    {
        if(ans!=0)
        {
            ans-=(2*4);
        }
        ans+=((2*sum_of_6_natural_nos)-((2*1)+(2*2)));//Now, the 2 dice touching the base wil have 1s on their base so that will not be visible and on sideways for each dice,
      //only one face will be covered so we take it as min possible after 1 as 1 is already covered so we subtract 2 times 2 further.
    }
    else if(rem==3)
    {
        if(ans!=0)
        {
            ans-=(3*4);//as on top layer, now 3 dice are added covering the 3 fours of the previously visible topmost layer
        }
    
        ans+=((3*sum_of_6_natural_nos)-((2*3)+(3*1)+(3*1))); //For three similarly, the bases would be 1, and same as condition rem=2, it will have 2 coinciding sideways 
      //of 2 dices, then one dice common to one and the other dice common to both whose 2 is already covered will overlap with faces 3(as 2 is already covered) and 2.
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
