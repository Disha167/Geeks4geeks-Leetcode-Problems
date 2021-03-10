//The only key here is observation to observe when key is greater to move left and when key is smaller to move down.We cover at most m cells of row and n cells of coloumn
//starting from topmost right when the element is present in bottomost left, so the time complexity is O(m+n)
  
  int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int i=0,j=M-1;
	   while((i>=0&&i<N)&&(j>=0&&j<M))
	   {
	       if(mat[i][j]==X)
	       return 1;
	       else if(mat[i][j]<X)
	       i++;
	       else if(mat[i][j]>X)
	       j--;
	   }
	   return 0;
	    // your code here
	}
