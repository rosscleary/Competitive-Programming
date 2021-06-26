#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
using namespace std;

const long long X=1000000001;

long long string_to_int(string);
int row_type(long long,long long,long long);
int fill_grid(long long[3][3]);
bool grid_works(long long[3][3]);
void print_grid(long long[3][3]);

int main () {

  string grid_str[3][3];
  long long grid[3][3];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cin>>grid_str[i][j];
    }
  }
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (grid_str[i][j]=="X") {
          grid[i][j]=X;
      }
      else {
        grid[i][j]=string_to_int(grid_str[i][j]);
      }
    }
  }

  fill_grid(grid);

  if (grid_works(grid)) {
    print_grid(grid);
    return 0;
  }

  for (int i=1; i<=10; i++) {
    for (int j=1; j<=10; j++) {
      for (int k=1; k<=10; k++) {
        for (int l=1; l<=10; l++) {
          long long new_grid[3][3]={0};
          for (int m=0; m<3; m++) {
            for (int n=0; n<3; n++) {
              new_grid[m][n]=grid[m][n];
            }
          }
          if (new_grid[0][0]==X) {
            new_grid[0][0]=i;
            if (fill_grid(new_grid) && grid_works(new_grid)) {
              print_grid(new_grid);
              return 0;
            }
          }
          if (new_grid[0][2]==X) {
            new_grid[0][2]=j;
            if (fill_grid(new_grid) && grid_works(new_grid)) {
              print_grid(new_grid);
              return 0;
            }
          }
          if (new_grid[2][0]==X) {
            new_grid[2][0]=k;
            if (fill_grid(new_grid) && grid_works(new_grid)) {
              print_grid(new_grid);
              return 0;
            }
          }
          if (new_grid[2][2]==X) {
            new_grid[2][2]=l;
            if (fill_grid(new_grid) && grid_works(new_grid)) {
              print_grid(new_grid);
              return 0;
            }
          }
        }
      }
    }
  }

  return 0;

}

long long string_to_int(string str) {

  bool negative=false;
  if (str[0]=='-') {
    negative=true;
  }

  long long number=0;
  int pow_ten=0;
  for (int i=str.length()-1; i>=negative; i--) {
    number+=(str[i]-'0')*pow(10,pow_ten);
    pow_ten++;
  }

  if (negative) {
    return -1*number;
  }
  return number;

}

int row_type(long long a, long long b, long long c) {

  if (a!=X && b!=X && c==X) {
    return 1;
  }
  if (a==X && b!=X && c!=X) {
    return 2;
  }
  if (a!=X && b==X && c!=X) {
    return 3;
  }

  return 0;

}

int fill_grid(long long grid[3][3]) {

  for (int i=0; i<3; i++) {
    int row_result=row_type(grid[i][0],grid[i][1],grid[i][2]);
    if (row_result==1) {
      grid[i][2]=grid[i][1]+(grid[i][1]-grid[i][0]);
    }
    if (row_result==2) {
      grid[i][0]=grid[i][1]-(grid[i][2]-grid[i][1]);
    }
    if (row_result==3) {
      if ((grid[i][0]+grid[i][2])%2!=0) {
        return 0;
      }
      grid[i][1]=(grid[i][0]+grid[i][2])/2;
    }
  }

  for (int i=0; i<3; i++) {
    int row_result=row_type(grid[0][i],grid[1][i],grid[2][i]);
    if (row_result==1) {
      grid[2][i]=grid[1][i]+(grid[1][i]-grid[0][i]);
    }
    if (row_result==2) {
      grid[0][i]=grid[1][i]-(grid[2][i]-grid[1][i]);
    }
    if (row_result==3) {
      if ((grid[0][i]+grid[2][i])%2!=0) {
        return 0;
      }
      grid[1][i]=(grid[0][i]+grid[2][i])/2;
    }
  }

  for (int i=0; i<3; i++) {
    int row_result=row_type(grid[i][0],grid[i][1],grid[i][2]);
    if (row_result==1) {
      grid[i][2]=grid[i][1]+(grid[i][1]-grid[i][0]);
    }
    if (row_result==2) {
      grid[i][0]=grid[i][1]-(grid[i][2]-grid[i][1]);
    }
    if (row_result==3) {
      if ((grid[i][0]+grid[i][2])%2!=0) {
        return 0;
      }
      grid[i][1]=(grid[i][0]+grid[i][2])/2;
    }
  }

  return 1;

}

bool grid_works(long long grid[3][3]) {

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (grid[i][j]==X) {
        return false;
      }
    }
  }

  for (int i=0; i<3; i++) {
    if (grid[i][1]-grid[i][0]!=grid[i][2]-grid[i][1]) {
      return false;
    }
  }
  for (int i=0; i<3; i++) {
    if (grid[1][i]-grid[0][i]!=grid[2][i]-grid[1][i]) {
      return false;
    }
  }

  return true;

}

void print_grid(long long grid[3][3]) {

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }

}