#include<stdio.h>
#include<math.h>
int c_board[20],count;
//function for printing the solution
void display(int n)
{
    int i,j;
    printf("\n\nSolution %d:\n\n",++count);
    for(i=1; i<=n; ++i)
        printf("\t%d",i);
    for(i=1; i<=n; ++i)
    {
        printf("\n\n%d",i);
        for(j=1; j<=n; ++j) //for n x n board
        {
            if(c_board[i]==j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
    }
}
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
    int i;
    for(i=1; i<=row-1; ++i)
    {
//checking column and digonal conflicts
        if(c_board[i]==column)
            return 0;
        else if(abs(c_board[i]-column)==abs(i-row))
            return 0;
    }
    return 1; //no conflicts
}
//function to check for proper positioning of queen
void queen(int row,int n)
{
    int column;
    for(column=1; column<=n; ++column)
    {
        if(place(row,column))
        {
            c_board[row]=column; //no conflicts so place queen
            if(row==n) //dead end
                display(n); //printing the board configuration
            else //try queen with next position
                queen(row+1,n);
        }
    }
}
int main()
{
    int n,i,j;
    printf("N-Queens Problem Using Backtracking:");
    printf("\n\nEnter number of Queens:");
    scanf("%d",&n);
    queen(1,n); // 1 is first row and n is no. of queens
    return 0;
}