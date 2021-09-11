//It is a greedy approach!
//Here we have to make choices in recursion very cleverly, instead of converting start to end, we focus on converting end to start as when converting start from end for
//eg. if start=4 end=6, then we first decrement start then multiply it by 2 to get end so there is no fixed order of the two operations, we can perform any operation
//before any other. But , when we do it in reverse order, we know that we will get the optimised result when we divide end by 2 untill it becomes less than start
//and then add it.
int help(int start,int end)
{ 
    if(start==end)
    return 0;
    if(start>end||end<=0)
    return start-end;
    if(end%2==0)
    return help(start,end/2)+1;
    return help(start,(end+1)/2)+2;
}
int solve(int start, int end) {
    int count=help(start,end);
    return count;
    
}
