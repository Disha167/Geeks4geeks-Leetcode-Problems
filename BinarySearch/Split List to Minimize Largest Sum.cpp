Intuition
Typical MINI-MAX Binary Search Problem:
In binary search, we need two things one search space & another a condition to eliminate one half at every step in binary search. Here, we have to give answer in terms of sum of k sublists,
and we have to minimise the maximum sum of k sublists so we make a guess on sum of sublists. The sum can be minimum maximum of the array as the sublists will be non -empty.
And, on increasing the mid value, i.e. maximum sum of k sublists possible , the no of sublists possible decreases and on decreasing, it increase so we get the condition of eliminating one-half of search space & it boils down to a binary search problem.

Implementation
We go through the search space and try to minimise it by min_ans = min(min_ans, mid) if the particular mid is possible otherwise maximise it to make it a valid answer

Time Complexity
\mathcal{O}(nlogn)O(nlogn) n for traversing the array linearly every time to check whether mid is valid or not, and log(n) for iterating over mid in the search space.

Space Complexity
\mathcal{O}(1)O(1) No more extra space is required

bool isPossible(int mid, vector<int>& nums, int k) {
    int sum = 0;
    int count = 1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > mid) {
            count++;
            sum = nums[i];
        }
        if (count > k) /*we check here that if the largest sum is mid, then can we create k
                          non-rmpty sublists.*/
            return false;
    }
    return true;
}

int solve(vector<int>& nums, int k) {
    int sum = 0;
    int start = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        start = max(start, nums[i]); /*As the sublist is non-empty, so in worst case it can contain
                                        1 maximum element, in our search space start can't be 0*/
    }
    int end = sum;
    int min_ans = INT_MAX;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(mid, nums, k)) {
            min_ans = min(min_ans, mid);
            end = mid - 1; /*minimize*/
        } else
            start = mid + 1;
    }
    // if(min_ans==INT_MAX)
    // return 0;
    return min_ans;
}
