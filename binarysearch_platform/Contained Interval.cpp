//problem link: https://binarysearch.com/problems/Contained-Interval
//There is a naive solution where you can check one pair against all pairs for overlaping (O(n^2)) but another efficient solution of O(nlogn) would be to sort the array
//and then check for the overlaping of intervals in two conditions:
//1)When intervals[i][0]==intervals[i+1][0], so dosen't matter what is the realtion between intervals[i][1] and intervals[i+1][1], they will always be overlaping 
//intervals. Eg: [4,3], [4,1] are overlapping intervals, [4,3], [4,3] are overlapping intervals and [4,3], [4,5] are overlapping intervals.
//2)When intervals[i][0]<=intervals[i+1][0] as they are sorted so intervals[i][1]>=intervals[i+1][1] for making it overlapping. Eg: [1,5] , [2,3] are overlapping
//intervals but [1,5], [2,6] are not so if the first co-ordinate is lesser then second co-ordinate had to be greater for second interval to overlap in first.
bool solve(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
      for(int i=1;i<intervals.size();i++)
      {
          if(intervals[i][0]==intervals[i-1][0]) return true;
          if(intervals[i-1][1]>=intervals[i][1]) return true;
            
           
      }
      return false;
}
