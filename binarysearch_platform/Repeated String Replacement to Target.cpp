//Here, we have to replace all occurences of characters in s to some character such that it converts to t, many characters in s can map to the same character
//in t eg:    s=pyaa       t=bbdd                          ,here p and y can both point to same character b, hence s can be converted to t, it returns true.
//but one character in s cannot point to two different characters, eg:
//s=bbdd    t=pyaa                 ,here b can be either converted to p or b can be converted to y, the two operations are not possible simultaneously.
//This can be checked easily by a hashmap but there is one corner edge case to consider:: IMP!!!!!!
//If we have all the characters from a-z in s and all the characters from a-z in t but they are not equal, then deadlock would occur and in no case, s can
//be converted to t. s=abcdefghijklmnopqrstuvwxyz   t=bcdefghijklmnopqrstuvwxyza when we convert a to b in first step, then 
//s=bbcdefghijklmnopqrstuvwxyz.    t=bcdefghijklmnopqrstuvwxyza    ,it creates a situation of deadlock i.e. b cannot be matched to c and b at same time.
//It is possible when length of s is not 26 as we can convert a into some character other than b, like x (if x is not mapped with anything else already), so
//it prevents deadlock situation but if size of both s and t is 26 , all the other characters are already matched leaving no choice so s cannot be converted to t.

bool solve(string s, string t) {
    unordered_map<char,char>mp2;
     unordered_set<char> sset;
    unordered_set<char> tset;
    if(s.length()!=t.length())
       return false;
    for (int i = 0; i < s.size(); i++) sset.insert(s[i]);
    for (int i = 0; i < t.size(); i++) tset.insert(t[i]);
    if (sset.size() == 26 && tset.size() == 26 && s != t) return false;   
    string ans=s;   
   for(int i=0;i<s.length();i++)
   {
       
       if(mp2.find(s[i])!=mp2.end())
       {
           if(mp2[s[i]]!=t[i])
           return false;
       }
       else
       {
   
       mp2[s[i]]=t[i];
       }
   }
   return true;
}
