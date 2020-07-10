// for the driver code and main problem , refer: https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1/?track=sp-recursion&batchId=105
MAIN CODE
void subset(string ip, string op,vector<string>&vec)
{
//base condition
    if(ip.length()==0)
    {
        vec.push_back(op);
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    subset(ip,op1,vec);
    subset(ip,op2,vec);
    return;
}
MAIN CODE ENDS HERE
DRVER CODE HERE:-
vector <string> powerSet(string s)
{
    string ip=s;
    string op="";
    vector<string>vec;
    subset(ip,op,vec);
    return vec;
   //vec vector contains all the subsets of string as it's elements .
}
