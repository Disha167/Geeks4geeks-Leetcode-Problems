//A simple appraoch is to calculate factorial then count 0s in them but it gives overflow in big numbers. Another approach is:
//We have to calculate the number of trailing zeroes in the factorial of the number. The trailing zeros are due to the prime factors 2 and 5 only.
//So, if we have 28!, we calculate the number of single 5s by 28/5=5 i.e. in factors of 25,20,15,10,5 then the number of double 5s by 28/25=1 i.e. in factors of 25
//So, total number of trailing zeros i.e. no of 5s would be 5+1=6. We keep on multiplying denominator by 5 untill n/i>=1
int solve(int n) {
    int count=0;
    for(long long i=5;n/i>=1;i*=5)
    {
        count+=n/i;
        // cout<<count<<endl;

    }
    return count;
}
