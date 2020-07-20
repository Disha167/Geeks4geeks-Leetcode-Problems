//problem link: https://leetcode.com/problems/scramble-string/
class Solution {
public:
    //we use map for memoization i.e. for storing values
    unordered_map<string,bool>mp;
    int solve(string A,string B)
    {
        //great & great are scrambled strings
        if(A.compare(B)==0)
            return 1;
        //if great is divided as great and "" as it's two childrens, it is invalid
        if(A.length()<=1)
            return 0;
        int flag=0;
        int n=A.length();
        //making the key of the map
        string key=A;
        key.push_back(' ');
        key.append(B);
        if(mp.find(key)!=mp.end())
            return mp[key];
        for(int i=1;i<=n-1;i++)
        {
            //IF THE VALUE OF i=2 i.e.THE TWO PARTITIONS ARE gr & eat
            //when the children are swapped i.e. in case of great and ategr comparing gr & gr and eat & ate
            int contd1=(solve(A.substr(0,i),B.substr(n-i,i))==1)&&(solve(A.substr(i,n-i),B.substr(0,n-i))==1);
            //when the children are not swapped i.e. if A=great & B=great, comparing gr & gr and eat & eat
            int contd2=(solve(A.substr(0,i),B.substr(0,i))==1)&&(solve(A.substr(i,n-i),B.substr(i,n-i))==1);
            if(contd1||contd2)
            {
                flag=1;
                break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        //if the length is not equal, it can never be scrambled strings
        if(s1.length()!=s2.length())
        return 0;
    else if(s1.length()==0)
        return 1;
    else
    {
        if(solve(s1,s2))
            return 1;
        else
            return 0;
    }

    }
};
