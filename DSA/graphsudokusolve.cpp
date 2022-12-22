#include<iostream>
using namespace std;
int n=9;
int G[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
             {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
             {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
             {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
             {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
             {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
             {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
             {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
             {0, 0, 5, 2, 0, 6, 3, 0, 0} };

bool issafe(int row,int col,int num)
{

    for(int i=0;i<9;i++)
    {
        if(G[row][i]==num || G[i][col]==num)
        return false;
    }

    int startrow=row-row%3;
    int startcol=col-col%3;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(G[i+startrow][j+startcol]==num)
            return false;
        }
    }
    return true;
}

bool solvesudoku(int row,int col)
{
    if(row==n-1 and col==n)
    return true;

    if(col==n)
    {
        row++;
        col=0;
    }

    if(G[row][col]>0)
    return solvesudoku(row,col+1);

    for(int i=1;i<10;i++)
    {
        if(issafe(row,col,i))
        {
            G[row][col]==i;
           // cout<<i;

            if(solvesudoku(row,col+1))
            return true;
        }
        G[row][col]=0;
    }
    return false;
}

void print(){
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    if(solvesudoku(0,0));
    print();

     return 0;
}