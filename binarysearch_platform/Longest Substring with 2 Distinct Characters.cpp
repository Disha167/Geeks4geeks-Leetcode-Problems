//It has string, substring as well as an integer k with "longest" so it very well identifies as a sliding window problem. The approach is to move the end pointer untill
//we have got k distinct characters, when we get more than k distinct characters then  we minimize the window by moving the start pointer untill end pointer<string size.
//In this process, we keep on updating the window size and return the maximum window size that we get.
int solve(string s) {
    int start=0,end=0;
    int distinct_characters=0;
    map<char,int>mp;
    int len=0;
    while(end<s.size()&&start<=end)
    {
        mp[s[end]]++;
        if(mp.size()<2) //we use else if and not while here as after every time when we push the character into the map and do end ++ we have to check the condition
          //and then perform the steps accordingly
        {  
            len=max(len,end-start+1);
            end++;
        }
        else if(mp.size()==2)
        {
        // cout<<s[start]<<" "<<s[end]<<endl;
        len=max(len,end-start+1);
        end++;
        }
        else if(mp.size()>2)
        {
           
           while(mp.size()>2)
           {
               mp[s[start]]--;
               if(mp[s[start]]==0)
               { 
                   mp.erase(s[start]); //to maintain the window size, we erase the char from the map that has zero occurence.
               }
               start++;
           }
           end++;
        }
        

    }
    return len;
    
}
