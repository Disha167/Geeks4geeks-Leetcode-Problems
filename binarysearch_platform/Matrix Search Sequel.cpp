bool solve(vector<vector<int>>& matrix, int target) {
    /*So, we make use of the thing that the matrix is sorted to eliminate the numbers we don't need. The first element of every col is smallest, 
    so if we start from the top right corner of the matrix, and if the target is smaller than the element, then all the elements in that col cannot contain 
    target(as the col is sorted in increasing order), so we decrease the coloumn else increase the coloumn.*/
    int row=matrix.size();
    int col=matrix[0].size();
    int i=0,j=col-1;
    while(i<row&&j>=0)
    {
        if(matrix[i][j]==target)
        return true;
        if(matrix[i][j]>target)
        {
            j--;
        }
        else
        i++;
    }
    return false;
}
