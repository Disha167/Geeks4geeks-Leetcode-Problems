//problem link: https://practice.geeksforgeeks.org/problems/next-larger-element/0

//🥳🥳 Join Me in my Daily DSA journey. I will try to maintain consistency 🥵 🥵


//In Aditya Verma Channel,I learnt that to identify whether a ques. can
//be solved using stack can be determined by writing it's brute force.
//If in brute force, there are two for loops, and the variable
//of the inner for loop is dependent on outer.
//🧐 🧐I figured out from this question that stacks are used to
//change the time complexity of inner for loop from O(n) to O(1) with the
//help of it's push and pop amazing operations ❣️❣️❣️
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int size;
        cin>>size;
        vector<long long int>input;
        for(long long int i=0;i<size;i++)
        {
            long long int value;
            cin>>value;
            input.push_back(value);
        }
        stack<long long int>st;
        st.push(input[size-1]);
        vector<long long int>res;
        res.push_back(-1);
        for(long long int i=size-2;i>=0;i--)
        {
            while(!st.empty()&&st.top()<input[i])
            {
                st.pop();
            }
            if(st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            st.push(input[i]);
        }
        reverse(res.begin(),res.end());
        for(auto it=res.begin();it!=res.end();it++)
            cout<<*it<<" ";
        cout<<endl;

    }

}
