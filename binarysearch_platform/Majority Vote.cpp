int solve(vector<int>& nums) {
    /*We use boyer moore's vote algorithm to find the majority element, it uses the fact that if one element occurs more than n/2 times then other elements occur less than n/2*/

    /*So we check for every element and keep on increasing the count till we find the same element, when we find a different element, we decrease the count as if the element is majority, then it should outweigh different elements, if our count becomes 0 that means the different elements are same as majority element, so we update our majority element.We repeat the process for every element*/
    int count=1,majority_index=0;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[majority_index]==nums[i])
            count++;
        else
        count--;
        if(count==0)
        {
            majority_index=i;
            count=1;
        }    
    }

    int majority_element=nums[majority_index];
    count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==majority_element)
        count++;
    }
    if(count>nums.size()/2)
    return majority_element;
    else
    return -1;
}
