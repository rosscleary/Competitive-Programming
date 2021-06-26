#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int m,n;
int grid_values[115][115];

int dp[105][105][3];
bool mem[105][105][3]={false};

int max_money(int row, int col, int last) {

if (mem[row][col][last]) {
  return dp[row][col][last];
}

if (grid_values[row][col]==-1) {
  return -1000000000;
}

if (row==1 && col==n) {
  return grid_values[row][col];
}

if (last==1) {
  dp[row][col][last]=grid_values[row][col]+max(max_money(row+1,col,2),max(max_money(row-1,col,3),max_money(row,col+1,1)));
}
else {
  if (last==2) {
    dp[row][col][last]=grid_values[row][col]+max(max_money(row+1,col,2),max_money(row,col+1,1));
  }
  else {
    dp[row][col][last]=grid_values[row][col]+max(max_money(row-1,col,3),max_money(row,col+1,1));
  }
}

mem[row][col][last]=true;
return dp[row][col][last];

}

int main () {

bool keep_going=true;

while (keep_going) {

  memset(dp,0,sizeof(dp));
  memset(mem,false,sizeof(mem));
  memset(grid_values,0,sizeof(grid_values));

  int c_m,c_n;

  cin>>c_m>>c_n;

  if (c_m==0 && c_n==0) {
    keep_going=false;
    break;
  }

  m=c_m;
  n=c_n;

  char grid_char[105][105];

  for (int i=m; i>=1; i--) {
    for (int ii=1; ii<=n; ii++) {
      cin>>grid_char[i][ii];
    }
  }

  for (int i=0; i<=110; i++) {
    for (int ii=0; ii<=110; ii++) {
      grid_values[i][ii]=-1;
    }
  }

  for (int i=m; i>=1; i--) {
    for (int ii=1; ii<=n; ii++) {
      if (grid_char[i][ii]=='.') {
        grid_values[i][ii]=0;
      }
      else {
        if (grid_char[i][ii]=='*') {
          grid_values[i][ii]=-1;
        }
        else {
          grid_values[i][ii]=grid_char[i][ii]-'0';
        }
      }
    }
  }

  cout<<max_money(1,1,1)<<endl;

}

return 0;

}