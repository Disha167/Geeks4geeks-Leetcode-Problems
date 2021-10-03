//Here, we need to find the longest valid parenthesis, eg. in (()())(((), the longest valid parenthesis is 6 i.e. (()()) . We can use stack and push all opening 
//brackets while popping it out and increasing the counter as we encounter closing brackets in the string. But, the problem occurs when we have to transit from
//one set of valid parenthesis to others, eg (())() will give 6 while (())(() will give 4, I could not think of any such condtion of keeping the track of the 
//last openend bracket and pairing it with the closed one so we push index in stack rather than just bracket and as we encounter a closing bracket, we make both
//set of closing and opening bracket valid.
int solve(string s) {
  stack<int>st;
  vector<int>arr(s.size(),0);
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='(')
    {
        st.push(i);
        
    }
    else if(!st.empty()) //it is necessary to check whether stack is not empty, as we have to access st.top()
    {
       arr[st.top()]=1;
       arr[i]=1;
       st.pop();
       
    }
 
  }
  int curr_count=0,count=0;
  //Then the problem reduces to counting of consecutive ones and then, we don't need to care about transisition from one set of valid parenthesis to another.
  for(int i=0;i<s.size();i++)
  {
      if(arr[i]==1)
      curr_count++;
      else
      {
          count=max(count,curr_count);
          curr_count=0;
      }
  }
  count=max(count,curr_count);
  return count;
}
