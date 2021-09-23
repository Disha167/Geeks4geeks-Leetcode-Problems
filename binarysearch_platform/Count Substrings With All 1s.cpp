//One naive appraoch is to calculate all substrings ad check whcih one has only 1s , it will take O(n^2) .To optimise it, we follow the given approach: 
//We have to calculate all substrings with 1s, so we consider all the blocks of strings having only 1s, and then count the number of substrings from that block.
//Eg in 011001111 , we keep a count of block 1 i.e. length 2 11 and block 2 i.e. length 4 1111 and then calculate no of substrings from each block.
int solve(string s) {
    int ans=0;
    for(int i=0;i<s.length();)
    {
        int count=0;
        if(s[i]=='1')
        {
            while(s[i]=='1')
            {
                count++;
                i++;
            }
            ans+=count*(count+1)/2; //IMP!!!!!!!!!!!!!!!!!
          //No of substrings that can be made from string of 4 length 1111 is 4*(4+1)/2=10. From where it came??
          //At every position, the number of substrings that can be made starting from same index is length from that index to end of string like in 1111,
          //no of substring from 1 index is 4 i.e. 1 11 111 1111, similarly for 2nd index, no of substring is 3 i.e. 1 11 111 , for 3rd index it is 2 i.e. 1 11
          //4th index it is 1 i.e. just 1 so the number of substrings in total is 1 + 2 + 3 + 4 = 4*(4+1)/2 in general n*(n+1)/2
        }
        else
           i++;
    }
  
    return ans;
}
