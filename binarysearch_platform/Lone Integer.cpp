//If we have to do it without using extra space, then we can play with bits. The approach can be to sum all occurences of 0 and 1 at a particular index, if number
//of 1s is not divisible by 3 that means the bit at this particular index is 1 in the lone integer occuring only once while if the number of 1s is divisible by 3
//then that bit accounts for the numbers that are occuring 3 times only.
//This approach is simple & logical but implementing it can be a little bit tricky, we maintain a vector of size 32 to keep a count of number of 1s at every index.
//Then we keep on oring our answer with 0 and 1 depending on whether number of 1s is divisible by 3 or not starting from 0th index (so that we can keep on shifting
//to the left), the tricky part is however to shift the ans to left but the shifting needs to be done 32-1=31 times so it needs to be shifted before the oring
//operation. Eg: if we consider 8 bits integer, then if we have 00001334 as our num_bit array so we first shift but our ans was 00000000 so it dosent make any
//difference till 4 iterations, then we or with 1 as 4 is not divisible by 3, our ans becomes 00000001.
//In 6th iteration, we just shift by 1 bit left and or with 0 as 3%3==0 , ans becomes 00000010
//In 7th iteration, shift by 1 bit left and or with 0, ans becomes 00000100
//In 8th iteration, shift by 1 bit or with 1 as 1%3!=0 , ans becomes 00001001
//Notice in 8th iteration, had we shifted after oring, then we had got 00010010, i..e wrong answer so we have to keep this in mind that logically also it is true,
//that alst operation should be or i.e. setting the last bit if we are running for loop 32 times so we get the exact number, shifting cant be the last operation
//as we have already set our last bit, shifting is not required now.
int solve(vector<int>& nums) {
    vector<int>num_bit(33,0);
    for(int i=0;i<nums.size();i++)
    {
        int number=nums[i];
        int index=32;
        while(number)
        {
            int temp=number&1;
            num_bit[index]+=temp;
            number=number>>1;
            index--;
        }
    }
    int ans=0;
    for(int i=0;i<=32;i++)
    {
        
          ans=ans<<1;
        if(num_bit[i]%3==0)
            ans=ans|0;
        else
            ans=ans|1;    
      
    }
    return ans;
}
