//The approach here is that if string is of any type and we keep on deleting two different adjacent letters i.e. 0 and 1, we get the non-different letters remaining at
//the end. For eg.: 
//If I have 1100000, then first we remove 2nd letter 1 and 3rd letter 0, then remove 1st letter 1 and 2nd letter 0, then we get 3 zeros at the end i.e. 
//absolute of diff of number of zeros and ones.
//Some edge cases are 00000 or 11111 so the absolute diff will handle it as the number of zeros and ones will be zero. 
int solve(string s) {
    int zeros=0,ones=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
          zeros++;
        else 
          ones++;  
    }
 
    
       return abs(zeros-ones);
}
