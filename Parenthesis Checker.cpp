//problem link: https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
//LOGIC IS SIMPLE : (But stack errors are very hard to deal with😔)
//What logic I have used: We push only the opening brackets and whenever we
//encounter a closing bracket, we pop the last opening bracket
//📌TAKE CARE EXAMPLES IF ABOVE APPROACH USED: {[]})))), in this case,
//the four ending brackets will remain as they are also not pushed in
//stack , so we have to maintain a count of closing brackets also and check
//at the end if it is equal to no. of opening brackets
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
        stack<string>st;
        int index=0;
        int count=0;
        while(index<str.size())
        {
            //📌Also, learnt HOW TO CONVERT CHARACTER TO STRING EASILY 
            string str1(1,str[index]);
            if(str1=="{"||str1=="("||str1=="[")
               //⭐️ Don't use push after using st.top()
               //TOP AND EMPTY ARE ONLY USED AFTER PUSHING AN ELEMENT
               st.push(str1);
            if(!st.empty()&&(str1=="]"||str1=="}"||str1==")"))
            {
                count++;
                st.pop();
            }

            index++;

        }
        //⭐️Use float for some cases like where 7/2=3.5!=3
        if(!st.empty()||count!=(float)index/2)
            cout<<"not balanced"<<endl;
        else
            cout<<"balanced"<<endl;
    }
	//code
	return 0;
}
