//Eg:
//Input: S = "a1b2"
//Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//just a small variation in permutation with case change problem in same repository in the if else condition
class Solution {
public:
    void permutation(string ip, string op,vector<string>&vec)
{
    if(ip.length()==0)
    {
        vector<string>::iterator it=find(vec.begin(),vec.end(),op);
        if(it==vec.end())
          vec.push_back(op);
        return;
    }
    string op1=op;
    string op2=op;
    if(isdigit(ip[0]))
    {
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
    }
    else
    {
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
    }
    ip.erase(ip.begin()+0);
    permutation(ip,op1,vec);
    permutation(ip,op2,vec);
    return;
}
    vector<string> letterCasePermutation(string S) {
        string ip=S;
        string op="";
        vector<string>vec;
        permutation(ip,op,vec);
        return vec;

    }
};

