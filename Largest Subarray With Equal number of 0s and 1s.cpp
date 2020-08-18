//Problem link: https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
int maxLen(int arr[], int N)
{
    //😋😋We make use of property of unordered set that it fimds an element in O(1)
    // 😎😎 Hashing reduces it's time complexty to O(n)
    unordered_map<int,int>um;
    for(int i=0;i<N;i++)
    {
        if(arr[i]==0)
            arr[i]=-1;
    }
    //📌We calculate prefix sum because: if prefix sum of 2nd index and 6th index is
    //same, then the sum of elements from 2nd to 6th index is 0.
    //I.E. WE HAVE TO CHECK WHETHER PREFIXSUM-SUM EXISTS IN THE ARRAY OR NOT
    //📌WE USE MAP HERE AS WE REQUIRE THE LAST INDEX OF FOUND NUMBER ALSO
    //TO FIND THE LENGTH
    int prefixsum=0;
    int resultIndex=0;
    for(int i=0;i<N;i++)
    {
        prefixsum+=arr[i];
        if(prefixsum==0)
        {
            resultIndex=max(resultIndex,i+1);

        }
          if(um.find(prefixsum)!=um.end())
        {
            resultIndex=max(resultIndex,i-um[prefixsum]);
        }
        if(um.find(prefixsum)==um.end())
        {
        //⭐️⭐️⭐️   IN HASHMAP,WE STORE  ONLY THE FIRST OCCURENCE OF EVERY PREFIXSUM
        //FOR THE MAXIMUM LENGTH
            um.insert(make_pair(prefixsum,i));
        }
    }
    return resultIndex;
}
