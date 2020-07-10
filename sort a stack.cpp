//for driver code , refer to the problem statement on gfg: https://practice.geeksforgeeks.org/problems/sort-a-stack/1

void insert(stack<int>&s,int top_of_stack)
{
    //base condition of insert function
    if(s.empty()||top_of_stack>s.top())
    {
        s.push(top_of_stack);
        return;
    }
    int top_in_insert_func=s.top();
    s.pop();
    //hypothesis of insert function
    insert(s,top_of_stack);
    //induction step of insert function
    s.push(top_in_insert_func);
}
void SortedStack :: sort()
{

    //base condition of sort function
    if (s.size()<=1)
        return;
    int top=s.top();
    s.pop();
    //hypothesis of sort function
    sort();
    //induction step of sort function
    insert(s,top);
}
//for more details of IBH method, refer Aditya Verma youtube channel
