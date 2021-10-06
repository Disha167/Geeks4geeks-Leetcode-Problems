/*
Intuition
It is given that at any step , we can move from position X to position k steps away and you have to end at last index, minimise the cost of this (every value of 
nums[i] is cost of pounding on that index). So, we have to check for ever index i, minimum of all possible ways to reach k indexes before it. We can do this by
iterating from i to i-k for every index and then storing in dp, but it will O(n*k) solution that gives tle.
To optimise this approach, we use deque for that O(k) operation to make it O(1).
It is using deque for solving the standard problem minimum element in sliding window of size k.

Implementation
We always maintain the minimum index at the front of the deque. For doing that, what we do is that before pushing back into the deque, we check that whether the 
element that we are pushing is less than the element at back of deque

while (!dq.empty() && dp[dq.back()] >= dp[i]) 
         dq.pop_back();
And, we keep on popping from back until the element is greater as we have got an optimised way to reach to the current index.We no longer reuire the bigger elements
if we have the smaller one. Also, we push indexes of element in
deque so that if the difference exceeds k, i.e. the element at front of deque becomes invalid , we pop from front.

   while (!dq.empty() && dq.back() - dq.front() >= k) 
         dq.pop_front();
So, we get the minimum element at front of queue and we keep on adding to current element for getting the answer for current index i.e. dp[i].

Now, the time complexity reduces to O(n)
*/

int solve(vector<int>& nums, int k) {
    deque<int> dq;
    int dp[nums.size() + 1] = {0};
    dq.push_back(0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        while (!dq.empty() && dq.back() - dq.front() >= k) dq.pop_front();
        int curr_min;
        curr_min = dp[dq.front()];
        dp[i] = curr_min + nums[i];
        while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    return dp[nums.size() - 1];
}
