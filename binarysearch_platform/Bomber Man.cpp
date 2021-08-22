//The approach is easy i.e. to mark all the rows and the coloumns that has a 1 in it, but we need to make sure that we are making only those rows and coloumns 1 whose 
//cells are originally 1, not those whose cells are made 1 due to bomb exploding .
//For that,we mark the first row and the first coloumn of the cell that needs to be damaged -1 after storing the flag, flag_row and flag_col for the first row and 
//coloumn. 
//Then, whosoever cell's row or col is -1 is made 1 and then the flags are checked for the first row and coloumn.
int solve(vector<vector<int>>& matrix) {
    int flag=0,flag_row=0,flag_col=0,count=0;
    if(matrix[0][0]==1)
        flag=1;
     
    for(int i=1;i<matrix.size();i++)
    {
        if(matrix[i][0]==1)
        {
            flag_row=1;
        }
    }    
    for(int j=1;j<matrix[0].size();j++)
    {
        if(matrix[0][j]==1)
        {
            
            flag_col=1;
        }
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==1)
            {
                matrix[i][0]=-1;
                matrix[0][j]=-1;
            }
        }
    }

    for(int i=1;i<matrix.size();i++)
    {
        for(int j=1;j<matrix[0].size();j++)
        {
            if(matrix[i][0]==-1||matrix[0][j]==-1)//we check if either of the row or coloumn is -1, then we make the cell damaged
            {
                
                matrix[i][j]=1;
            }
        }
    }
    if(flag==1)
    {
        for(int i=0;i<matrix.size();i++)
        {
            
            matrix[i][0]=1;
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            
            matrix[0][j]=1;
        }    
    }
    if(flag_row==1)
    {
        for(int i=0;i<matrix.size();i++)
            matrix[i][0]=1;
    }
    if(flag_col==1)
    {
        for(int j=0;j<matrix[0].size();j++)
            matrix[0][j]=1; 
    }
  //After making all the cells 1, the count of undamaged cells are checked!
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
           
            if(matrix[i][j]!=1&&matrix[i][j]!=-1)
            {
                count++;
            }
        }
    }
    return count;
}
