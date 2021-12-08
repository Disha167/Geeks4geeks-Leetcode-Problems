/*We just have to flip all the characters other than top k characters to minimise the no of flips(characters sorted by the frequency of the character */

/*maximum length of substring having k distinct characters cannot be used as we can flip any of the characters not necessarily the consecutive characters*/
int solve(string s, int k) {

    map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    if(mp.size()<=k)
    return 0;
    vector<int>count;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        
        count.push_back(it->second);
    }
    sort(count.begin(),count.end());
    int ans=0;
    for(int i=0;i<count.size()-k;i++)
    {
        ans+=count[i];
    }
    return ans;
   
}
