//We have to return whether we can fill the empty spaces in the sudoku,once we have tried simulating the sudoku solver backtracking technique on our
//puzzle, we check that whether it still contains any empty slot that we were not able to fill or it violates the property given in question.
bool isvalid(int row,int col,vector<vector<int>>&matrix,int c)
{
    for(int i=0;i<matrix.size();i++)
    {
        if(matrix[row][i]==c)
        return false;
        if(matrix[i][col]==c)
        return false;
    }
    return true;
}
bool sudoku(vector<vector<int>>& matrix, int n)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                for(int c=1;c<=n;c++)
                {
                    if(isvalid(i,j,matrix,c))
                    {
                        matrix[i][j]=c;
                        if(sudoku(matrix,n)==true)
                            return true;
                        else
                        matrix[i][j]=0; //if the next empty slot can't be filled given that the current slot is filled, we return false & try other
                        //numbers at current slot.
      
                    }
                } 
                return false; 
            }

        }
    }
    return true;
}
bool solve(vector<vector<int>>& matrix) {
    int n=matrix.size();
    sudoku(matrix,n);
    int arr[n+1]={0};
    for(int i=0;i<n;i++)
    {
        memset(arr,0,sizeof(arr));
        for(int j=0;j<n;j++)
        {
            arr[matrix[i][j]]++;
            if(arr[matrix[i][j]]>1||matrix[i][j]==0)
            return false;
        }
    }
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++)
    {
        memset(arr,0,sizeof(arr));
        for(int j=0;j<n;j++)
        {
            arr[matrix[j][i]]++;
            if(arr[matrix[j][i]]>1||matrix[i][j]==0) //other than checking whether there are dublicates in same row or coloumn, we also have to check
            //whether we were not able to fill a cell.
            return false;
        }
    }
    return true;

}
