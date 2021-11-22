/*So, here we have to find the number of sublist where first element is smaller or equal to all the elements in the sublist. 
Eg: For nums = [1, 3, 5, 2], The sublists will be 1  1,3  1,3,5  1,3,5,2(starting from 1)  3  3,5(starting from 3)  5(starting from 5)  2(starting from 2)  
Ideally if we take example of the above sublist, then there would be four sublists starting from one, 1 1,3 1,3,5 1,3,5,2 , three sublists starting from three, 
3 3,5 3,5,2 , two sublists starting from five, 5, 5,2 and one sublist starting from two(as it is the last element) .
Now, we have to check out of those sublists, how many sublists are there that has first element as smaller or equal to all elements in sublist. So, for that we 
check that is there any smallest element, eg for element 3 , there is a next smallest element on index 3(0-based indexing), i.e. 2 so the sublist 3,5,2 is invalid
as the first element is not smallest one, so we subtract all the sublists made after the smallest element from n-i, if first is not smallest, otherwise it
forms n-i sublists like in the case of 1, there is no next greater element on right so there are four valid sublists 1  1,3  1,3,5  1,3,5,2*/

int solve(vector<int>& nums) {
    /*We use next smaller element to find the ineligible candidates*/
    if(nums.empty()) return 0;
    vector<pair<int,int>>next_smaller;
    stack<pair<int,int>>st;
    st.push({nums[nums.size()-1],nums.size()-1});
    next_smaller.push_back({-1,-1});
    for(int i=nums.size()-2;i>=0;i--)
    {
        while(!st.empty()&&st.top().first>=nums[i])
        {
           st.pop();
        }

        if(!st.empty()&&st.top().first<nums[i])
           next_smaller.push_back(st.top());
        else
           next_smaller.push_back({nums[i],-1});   
        st.push({nums[i],i});   

    }
    reverse(next_smaller.begin(),next_smaller.end());
    int count=0;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(next_smaller[i].second==-1)
        count+=(nums.size()-i);
        else
         /*if there is some other smaller element other than first element then we can form valid sublists only till the index of smallest element -1 like in case 
         of 3, we could only form valid sublists till 5 as 2 was the next smaller element so we subtract that from all the sublists possible starting from that 
         index i.e. n-i*/
        count+=((nums.size()-i)-(nums.size()-next_smaller[i].second));
    }
    return count+1;
}


