/*Use the technique of binary to decimal conversion.*/
int solve(string s) {
    int num=0,index=0;
    int n=s.size();
    for(int i=n-1;i>=0;i--)
    {
        num=num+(pow(26,index)*(s[i]-'A'+1));
        index++;
    }
    return num;
}
/*Today, understood the big picture of binary to decimal, we multiply 2^0*0+ 2^1*0 + 2^2*1 as the binary representation of 4 looks like 100 because there have been
2 numbers 2 and 3 before 4 representing 011 and 010 and one number 0001 and similarly 5 is written as 101 2^0*1+ 2^1*0 + 2^2*1 because there are again 3 numbers 
1,2,3 and 4 itself so this is true meaning of the binary representation.
Similarly, we do for A,B,C...Z there are 26 symbols
Then AA,AB... ZZ 26*26 symbols so this can be converted similar to decimal system.*/
