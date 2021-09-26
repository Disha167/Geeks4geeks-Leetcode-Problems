//One brute force approach is to compare for every string, every other string in the words list and as soon as more than 1 word differ, break and if we have 
//traversed whole and only one word differ i.e. count==1 then return true. Time complexity would be O(n^2*max length of word)
bool solve(vector<string>& words) {
   
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words.size();j++)
        {
            int count=0;
            if(j!=i)
            {
                for(int k=0;k<words[j].size();k++)
                {
                    if(words[j][k]!=words[i][k])
                    count++;
                    if(count>1)
                    break;
                } 
                if(count==1)
                return true; 
            }
        }
    }
    return false;
}

//Another interesting approach is to increase the complexity for length of string in word list rather than word length. We can put * at every index of string and
// push the mask hence formed in the set seen. If the mask is already been pushed that means that there is an almost same string present in the list. 
//Eg for abcd, the masks would be *bcd, a*cd, ab*d, abc*.


bool solve(vector<string>& words) {
    unordered_set<string>seen;
    for(auto w:words)
    {
        for(char &c:w)
        {
            char temp=c;
            c='*';
            if(!seen.insert(w).second) return true;
            c=temp;

        }
    }
    return false;
}
