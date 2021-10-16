int solve(vector<int>& nums) {
    if(nums.empty())return 0;
 /*
Ques me array kuch aise format ka hai ascending+x+ascending,aage se check krna hoga kahan tk ascending hai.. peeche se check krna hoga kahan tk descending hai fir har valid index ke liye dekho ki ascending wale portion ka last element descending wale portion ke first element se chhota hai ya ni
 One way of removing shortest sublist that is not in ascending order is joining to 2 sorted lists together.
 */ 
 /*
 There might be 3 cases:
 nums=[1,2,5,4,3] : the prefix 1,2,5 is in ascending order
 (sublist in descending order is removed from end)
 nums=[7,6,3,1,2] : the suffix 1,2 is in ascending order
 (sublist in descending order is removed from beginning)
 nums=[1,2,8,7,6,5,9]: the list is taken both from prefix and suffix 1,2,5,9 (sublist from middle is removed)

LOGIC!!!!
 SO FOR THE FIRST TWO CASES WE HAVE TO KEEP ON INCREASING THE START POINTER UNTILL IT IS IN ASCENDING ORDER & KEEP ON DECREASING THE END POINTER UNTILL IT IS IN ASCENDING ORDER.
 BUT,
 for third case , we have to check for every index whether nums[i]<=nums[j], if it is true then we increase i and try to minimise the answer but when it becomes false, we increase j to make the condition valid again.
 */
int start=0;
while(start<=nums.size()-2&&nums[start]<=nums[start+1])
{
    start++;
}
int end=nums.size()-1;
while(end>=1&&nums[end-1]<=nums[end])
{
    end--;
}
if(start==nums.size()-1||end==0)
return 0;
int ans=INT_MAX;
/* for cases 1,2,0,0*/
ans=min(end,(int)nums.size()-start-1);
int i=0,j=end;
// cout<<start<<" "<<end<<endl;
while(i<=start&&j<nums.size())
{
    if(nums[i]<=nums[j])
    {
        ans=min(ans,j-i-1);
        i++;
    }
    else
        j++;
}
return ans;
}
