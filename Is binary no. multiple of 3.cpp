//problem link: https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0/
//IT FORMS A PATTERN LIKE 64 32 16 8 4 2 1 are powers of 2 till 6🥱🥱
//We take two even bit sum like 0 and 2 sum being 5 & two odd bit like
//1 and 3 sum being 10 and their sum total is 15 i.e.divisible by 3
//So, the set bits in the number given should have the difference
//in count %3==0 like in above case the difference is 0.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        long long int count_of_even_set_bit=0;
        long long int count_of_odd_set_bit=0;
        long long int len=str.length();
        long long int new_i=0;
        for(int i=len-1;i>=0;i--)
        {
            if(str[i]=='1'&&new_i%2==0)
            {
                //cout<<"even"<<" "<<new_i<<endl;
                count_of_even_set_bit++;
            }
            else if(str[i]=='1'&&(new_i%2!=0))
            {
                //cout<<"odd"<<" "<<new_i<<endl;
                count_of_odd_set_bit++;
            }
            new_i++;
        }


        if((count_of_even_set_bit-count_of_odd_set_bit)%3==0)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }
	//code
	return 0;
}
