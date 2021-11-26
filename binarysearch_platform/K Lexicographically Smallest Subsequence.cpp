/*The approach isvery basic to just pop from the dq if the upcoming element is smaller than dq.back and vector has enough elements after that to complete a 
subsequence of size k i.e. (dq.size() + s.size()-i-1)>=k*/
vector<int> solve(vector<int>& s, int k) {
     deque<int> dq;
    for(int i = 0; i < s.size(); i++) {
        while(!dq.empty() && s[i] < dq.back() && (dq.size() + (s.size() - i - 1)) >= k) {
            dq.pop_back();
        }
        dq.push_back(s[i]);
    }
    // if(dq.empty()) return {};
    vector<int>ans; 
    /*if the subsequence is larger, to reduce the subsequence to size k*/
    while(!dq.empty()&&k)
    {
        ans.push_back(dq.front());
        dq.pop_front();
        k--;
    }
    return ans;
}
