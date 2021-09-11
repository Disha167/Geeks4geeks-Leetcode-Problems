//We have to return the minimum possible interval such that on combining all, we have just one interval.
//So, our approach is to just find the first interval's 2nd co-ordinate that is lesser than 1st co-ordinate of consecutive interval and similarly from the back find the
//first interval's first co-ordinate that is greater than previous interval's second co-ordinate.
//Before, that we deal with overlapping intervals and merge all of them: For eg.: {1,4} and {2,3} is merged to {1,4}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size()==1)return intervals;
        sort(intervals.begin(),intervals.end());
      stack<vector<int>>st;
        st.push(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> tp=st.top();
            if(tp[1]>=intervals[i][0])
            {
                st.pop();
                st.push({tp[0],max(tp[1],intervals[i][1])});
            }
            else
            {
                st.push({intervals[i][0],intervals[i][1]});
            }
        }
        while(!st.empty())
        {
            vector<int> tp=st.top();
            ans.push_back({tp[0],tp[1]});
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>temp=merge(intervals);
    intervals=temp;
    int start=0,end=0;
    for(int i=0;i<intervals.size()-1;i++)
    {
        if(intervals[i][1]<intervals[i+1][0])
        {
        start=intervals[i][1];
        break;
        }
    }
    for(int i=intervals.size()-1;i>0;i--)
    {
        if(intervals[i][0]>intervals[i-1][1])
        {
        end=intervals[i][0];
        break;
        }
    }
    return end-start;
}
//3,4 19,20 39,64
