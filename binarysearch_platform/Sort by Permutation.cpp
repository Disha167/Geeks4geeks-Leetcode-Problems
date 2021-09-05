//As it needs to be done in O(1) space, swap sort will be used. The element at a particular index is swapped untill the element at this index is the right one, here is 
//the trick that with swapping the characters, you will also swap the numbers and when a 0 number comes at the zero index, it means that at the current position,
//correct character is placed and you iterate to the next index.
//Eg. in lst: [a b c d]
//         p: [3 0 1 2]
//Swap a with element at 3rd index, thus swapping  3 and 2 in p array. we will get
//       lst: [d b c a]
//         p: [2 0 1 3]
//Swap d with element at 2nd index, thus swapping 2 and 1 in p array, we will get
//       lst: [c b d a]
//         p: [1 0 2 3]
//Swap c with element at 1st index, thus swapping 1 and 0 in array, we will get
//       lst: [b c d a]
//         p: [0 1 2 3]
//Now 0 number is at 0th index, so we move to next index.
vector<string> solve(vector<string>& lst, vector<int>& p) {
    // unordered_map<string,int>mp;
    // for(int i=0;i<lst.size();i++)
    // {
    //     mp.insert({lst[i],i});
    // }
    for(int i=0;i<lst.size();i++)
    {
        while(p[i]!=i)
        {  
            string temp=lst[p[i]];
            lst[p[i]]=lst[i];
            lst[i]=temp;
            int temp1=p[p[i]];
            p[p[i]]=p[i];
            p[i]=temp1;
        }
    }
    return lst;
}
