//Sometimes things have to be seen differently for solving a problem.
//Here, a brute force approach can be used easily by first pushing back and then sorting but the time complexity will be O(nlogn)
//An O(n) two pointer approach is preferred, where there can be two, three scenarios: -3 -2 0 1 2,     1 2 3 4 5
//The second example can be dealt easily but for first what we do is we maintain 2 pointers at start and end of the array and which ever number is big we keep on pushing
//in the array and keep on increasing left and decreasing right consequently eg: in the above example first push 3, the increase left then push 2 from both sides, then
//move both right and left , then push 1 and decrease right and then 0.. and so on
vector<int> solve(vector<int>& nums) {
    int left=0,right=nums.size()-1;
    vector<int>ans(nums.size());
    int i=nums.size()-1;
 while(left<=right)
 {
    if(abs(nums[left])<=nums[right])
    {
        ans[i]=nums[right]*nums[right];
        right--;
    }
    else
    {
        ans[i]=nums[left]*nums[left];
        left++;
    }
    i--;

 }
 return ans;
    
}
