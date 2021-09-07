//We can also use some map sort of thing. Another approach is to:
//We do swap sort to place every integer on their respective indexes, we just add another condition that if the nums[nums[i]-1] and nums[i] are same , then there is
//no point in swapping and it will turn to infinite loop. 
vector<int> solve(vector<int>& nums) {
    for(int i=0;i<nums.size();i++)
    {
//         cout<<nums[i]<<" "<<i<< "out"<<endl;
        while((nums[i]-1!=i)&&(nums[nums[i]-1]!=nums[i]))
        {
//             cout<<nums[i]<<" "<<nums[nums[i]-1]<<endl;
            int temp=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];//Just care here that you cant assign nums[i] to temp and then change nums[i] in second line, and then use the changed nums[i] as
          //index for nums[nums[i]-1].You have to use nums[nums[i]-1] in 1st line to avoid that.
            nums[i]=temp;
        }
    }
    vector<int>ans;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]-1!=i)
        ans.push_back(i+1);
    }
    return ans;

}
