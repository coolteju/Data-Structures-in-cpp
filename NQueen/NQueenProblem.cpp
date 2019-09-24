#include<iostream>
#include<stdlib.h>

using namespace std;

int rowsAndColumns=0;
int queens=0;
int placedQueens=0;

int **chessBoard=NULL;

int main(void)
{
    //function declarations
    void printArray();
    bool checkQueen(int,int);
    bool placeQueen(int);


    cout<<"\nEnter the number of ROWS and COLUMNS: ";
    cin>>rowsAndColumns;

    queens=rowsAndColumns;

    chessBoard=(int**)malloc(rowsAndColumns*sizeof(int*));
    for(int i=0;i<rowsAndColumns;i++)
    {
        chessBoard[i]=(int*)malloc(rowsAndColumns*sizeof(int));

    }

    placeQueen(0);
    

    printArray();

    return 0;
}

bool placeQueen(int col)
{
    bool checkQueen(int,int);
    if(col>=rowsAndColumns)
    {
        cout<<"\n in placeQueen";
        return true;
    }    

    for(int i=0;i<rowsAndColumns;i++)
    {
        cout<<"\n in placeQueen for<<"<<col;
        if(checkQueen(i,col))
        {
             cout<<"\n in placeQueen for<<<<<<<"<<i<<" "<<col;
            chessBoard[i][col]=1;
            if(placeQueen(col+1)){
                cout<<"\n recurr placeQueen";
                return true;
            }
            cout<<"\n chessboard: "<<i<<" "<<col;
            chessBoard[i][col]=0;
        }    
    }
    return false;
}

bool checkQueen(int row, int col)
{
    void printArray();

     cout<<"\n in checkQueen";
     cout<<"\nrow "<<row<<" "<<"col "<<col;
    for(int i=0;i<col;i++)
    {
        if(chessBoard[row][i])
        {
            cout<<"\ncheck for current left row "<<row<<" "<<i<<" "<<chessBoard[row][i];
            printArray();
            return false;
        }
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
         cout<<"\n 1-in placeQueen left upper  dignoal"<<i<<" "<<j<<" ";
         cout<<"\n"<<chessBoard[i][j];
        if(chessBoard[i][j])
        {
            cout<<"\n 2-in placeQueen left upper dignoal"<<i<<" "<<j;
            return false;
        }
    }
    for(int i=row,j=col;i<rowsAndColumns&&j>=0;i++,j--)
    {
        cout<<"\n 1-in placeQueen left down dignoal"<<i<<" "<<j;
        if(chessBoard[i][j])
        {
             cout<<"\n2- in placeQueen left down dignoal"<<i<<" "<<j;
            return false;
        }
    }
    return true;
    
}

void printArray()
{
    cout<<"\n\n";
    for(int i=0;i<rowsAndColumns;i++)
    {
        for(int j=0;j<rowsAndColumns;j++)
        {
            cout<<"\t"<<chessBoard[i][j];       
        }
        cout<<endl;
    }

}