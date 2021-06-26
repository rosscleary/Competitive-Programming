#include <iostream>
using namespace std;

long long int mem[1001][1001]={0};
bool mem_if[1001][1001]={false};

long long int num_paths(int row, int col, char **grid, int row_num, int col_num) {

if (mem_if[row][col]!=false)
    return mem[row][col];

if (row==row_num && col==col_num)
    return 1;
 
long long int num_ways=0;

if (col<=col_num-1 && grid[row-1][col]=='.')
    num_ways=(num_ways)+(num_paths(row,col+1,grid,row_num,col_num));    
    
if (row<=row_num-1 && grid[row][col-1]=='.')
    num_ways=(num_ways)+(num_paths(row+1,col,grid,row_num,col_num));
    
mem_if[row][col]=true;
mem[row][col]=num_ways;
return num_ways%1000000007;

}

int main () {
    
int row_num;
int col_num;
char **grid;

cin>>row_num;
cin>>col_num;

grid=new char*[row_num];

for (int i=0; i<=row_num-1; i++)
grid[i]=new char[col_num];

for (int i=0; i<=row_num-1; i++) {
    for (int ii=0; ii<=col_num-1; ii++)
    cin>>grid[i][ii];
}

int row=1;
int col=1;

cout<<(num_paths(row,col,grid,row_num,col_num))<<endl;

return 0;
}