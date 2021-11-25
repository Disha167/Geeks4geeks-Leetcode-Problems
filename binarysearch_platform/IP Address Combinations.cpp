/*The key observation here is that we only have to place 3 dots, so we can try all combinations & do it iteratively.*/
bool isPossible(string str)
{
    if(str.size()==0)
    return false;
    if(str.size()==1)
    return true;
    if(str.size()==2||str.size()==3)
    {
        if(str[0]=='0')
        return false;
    }
    if(str.size()>3)
    return false;

    int val=stoi(str);
    if(val>=0&&val<=255)
    return true;
    else
    return false;
}
vector<string> solve(string ip) {
    vector<string>ans;
  /*The three loops are used for placing the three dots at different places*/
    for(int i=0;i<ip.size();i++)
    {
        for(int j=i+1;j<ip.size();j++)
        {
            for(int k=j+1;k<ip.size();k++)
            {
                string str1=ip.substr(0,i);
                string str2=ip.substr(i,j-i);
                string str3=ip.substr(j,k-j);
                string str4=ip.substr(k,ip.size()-k);
                if(isPossible(str1)&&isPossible(str2)&&isPossible(str3)&&isPossible(str4))
                {
                   
                    string curr_ans=str1+"."+str2+"."+str3+"."+str4;
                    ans.push_back(curr_ans);
                } 
            }
        }
    }
    return ans;
}
