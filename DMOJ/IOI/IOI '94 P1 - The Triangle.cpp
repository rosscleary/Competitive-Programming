#include <iostream>
#include <algorithm>
using namespace std;

int n;
int triangle[101][200];
int mem[101][200];

int best_path(int,int);

int main () {

cin>>n;

for (int i=1; i<=n; i++) {

for (int ii=((n+(n-1))/2)+1-(i-1); ii<=((n+(n-1))/2)+1+(i-1); ii=ii+2)
cin>>triangle[i][ii];

}

cout<<best_path(1,((n+(n-1))/2)+1)<<endl;

return 0;

}

int best_path(int row, int col) {

if (mem[row][col])
  return mem[row][col];

if (row==n)
  return triangle[row][col];

int result=max(triangle[row][col]+best_path(row+1,col-1),triangle[row][col]+best_path(row+1,col+1));

mem[row][col]=result;
return result;

}