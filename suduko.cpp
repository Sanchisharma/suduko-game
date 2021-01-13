#include <iostream>
using namespace std;
#define n 9
void print(int mat[n][n])
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
 

bool isSafe(int mat[n][n], int row, 
                       int col, int num)
{
     
    
    for (int x = 0; x <= 8; x++)
        if (mat[row][x] == num)
            return false;
 
  
    for (int x = 0; x <= 8; x++)
        if (mat[x][col] == num)
            return false;
 
   
    int startRow = row - row % 3, 
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i + startRow][j + 
                            startCol] == num)
                return false;
 
    return true;
}
 
bool solveSuduko(int mat[n][n], int row, int col)
{
    
    if (row == n - 1 && col == n)
        return true;
 
    
    if (col == n) {
        row++;
        col = 0;
    }
   
    
    if (mat[row][col] > 0)
        return solveSuduko(mat, row, col + 1);
 
    for (int num = 1; num <= n; num++) 
    {
         
        // Check if it is safe to place 
        // the num (1-9)  in the
        // given row ,col  ->we 
        // move to next column
        if (isSafe(mat, row, col, num)) 
        {
             
           /* Assigning the num in 
              the current (row,col)
              position of the grid
              and assuming our assined 
              num in the position
              is correct     */
            mat[row][col] = num;
           
            //  Checking for next possibility with next
            //  column
            if (solveSuduko(mat, row, col + 1))
                return true;
        }
       
       
        mat[row][col] = 0;
    }
    return false;
}

int main()
{
    int mat[n][n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>mat[i][j];
		}
	}
 
    if (solveSuduko(mat, 0, 0))
        print(mat);
    else
        cout << "no output Exist!!!!" << endl;
 
    return 0;
}

