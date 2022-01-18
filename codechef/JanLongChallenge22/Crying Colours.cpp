/*We have to make all red balls to go to first row, all green balls to go to 2nd row & all blue balls to go to 3rd row. So we make a direct swap b/w red & green 
balls in 1st & second row, green & blue balls in 2nd & 3rd row, blue & red balls in 3rd & 1st row i.e. like for 3rd operation we make minimum of arr[2][0],arr[0][2]
After direct swap , we can calculate indirect swap by N-direct swap & then we have to swap it 2 times red & blue first (b/w 1st & 2nd row)and then blue & green (b/w
1st & 3rd row) so a+c and then we have to do it 2 times for getting all 3 rows desired.*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void tests() {

    int N;
    cin>>N;
    int arr[3][3];
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cin>>arr[i][j];
    }
    
    int count=0;
    int a=0,b=0,c=0;
    a=min(arr[0][1],arr[1][0]);
    b=min(arr[1][2],arr[2][1]);
    c=min(arr[2][0],arr[0][2]);
    int direct_swap=a+b+c;
    /*calculating direct swap for 1 row, let's say red*/
    int direct_swap_for_one=arr[0][0];
    direct_swap_for_one+=(a+c);
    /*indirect swap for one would be N-direct_swap_for_one*/
    cout<<direct_swap+2*(N-direct_swap_for_one)<<"\n";
    
    
    
    

      

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
