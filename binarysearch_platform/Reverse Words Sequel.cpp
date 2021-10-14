//The approach is to store all the words seperated by delimiters in a vector and then reverse the vector. Then, we make a mask type thing for maintaining the order
//of words and delimiters.
//EG: If sentence = "hello/world:here"
//       delimiters = ["/", ":"]
//then the mask created would be 0/0:0, and then, iterating thorugh the mask whenever we get 0, we push 1 vector else push the delimiter and then return the answer.
string solve(string sentence, vector<string>& delimiters) {
    if(delimiters.empty()) return sentence;
    vector<string>vec;
    unordered_set<char>forbidden;
    for(int i=0;i<delimiters.size();i++)
    forbidden.insert(delimiters[i][0]);
    string handler="";
    for(int i=0;i<sentence.size();)
    {
        string temp="";
        if(forbidden.find(sentence[i])==forbidden.end())
        {
            handler+="0";
            while(i<sentence.size()&&forbidden.find(sentence[i])==forbidden.end()) //we keep on adding the letters untill it is not a delimiter and then push the 
              //whole word in the vector
            {
                temp+=sentence[i];
                i++;
            }
            vec.push_back(temp);
        }
        else
        {
            handler+=sentence[i];
            i++;
        }
    }
    reverse(vec.begin(),vec.end());
    auto it=vec.begin();
    string ans="";
    // for(int i=0;i<handler.size();i++)
    // cout<<handler[i];
    // cout<<endl;
    //Iterate over the mask, and if it is not 0, push as it is. If it is 0, push a vector and return the string at the end.
    for(int i=0;i<handler.size();)
    {
        if(handler[i]!='0'&&forbidden.find(handler[i])!=forbidden.end())
        {
           
            while(i<handler.size()&&handler[i]!='0'&&forbidden.find(handler[i])!=forbidden.end())
            {
                ans+=handler[i];
                i++;
            }  
        }
        else if(handler[i]=='0')
        {
            
            if(it!=vec.end())
            {
                string temp=*it;
                for(int j=0;j<temp.size();j++)
                ans+=temp[j];
                it++;
            }
            i++;
        }
        
    }
    while(it!=vec.end())
    {
        string temp=*it;
        for(int j=0;j<temp.size();j++)
        ans+=temp[j];
        it++;
    }
    return ans;
    
}
