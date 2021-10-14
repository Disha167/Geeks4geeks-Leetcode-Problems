//This is a classic sliding window problem, we keep on extending our window untill there are all distinct elements and whenever we find a dublicate, then we keep on
//incrementing start++ and squeezing the window to make it valid again.
//The mistake everyone makes here is doing end++ before you update the max_len, we do end++ after updating as we first check which condition current end belongs to
//according to s.find(nums[end]..... . Also, our end do not increases in the 2nd condition as we just increase the start adn first process the current end and then
//increase it(here , process means adding it to set)
int solve(vector<int>& nums) {
    int start=0, end=0;
    unordered_set<int>s;
    int max_len=0;
    while(end<nums.size()&&start<=end)
    {
        // cout<<start<<" "<<end<<" "<<nums[end]<<endl;
        if(s.find(nums[end])==s.end())
        {
            s.insert(nums[end]); 
             max_len=max(end-start+1,max_len); 
            end++;      
        }
        else 
        {
            while(s.find(nums[end])!=s.end())
            {
                s.erase(nums[start]);
                start++;
            }

        }


    }
    return max_len;
}
