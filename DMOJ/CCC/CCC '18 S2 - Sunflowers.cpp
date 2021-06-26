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

int n;

void rotate_grid(int grid[101][101]);
bool valid_grid(int grid[101][101]);
void print_grid(int grid[101][101]);

int main () {

  cin>>n;
  int grid[101][101];
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin>>grid[i][j];
    }
  }

  if (valid_grid(grid)) {
    print_grid(grid);
  }
  else {
    rotate_grid(grid);
    if (valid_grid(grid)) {
      print_grid(grid);
    }
    else {
      rotate_grid(grid);
      if (valid_grid(grid)) {
        print_grid(grid);
      }
      else {
        rotate_grid(grid);
        print_grid(grid);
      }
    }
  }

  return 0;

}

void rotate_grid(int grid[101][101]) {

  int new_grid[101][101];
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      new_grid[i][j]=grid[j][n-(i-1)];
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      grid[i][j]=new_grid[i][j];
    }
  }

}

bool valid_grid(int grid[101][101]) {

  for (int i=1; i<=n; i++) {
    for (int j=2; j<=n; j++) {
      if (grid[i][j]<=grid[i][j-1]) {
        return false;
      }
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=i+1; j<=n; j++) {
      for (int k=2; k<=n; k++) {
        if (grid[i][k]<grid[i][k-1]!=grid[j][k]<grid[j][k-1] || grid[j][k]<grid[i][k] || grid[j][k-1]<grid[j][k-1]) {
          return false;
        }
      }
    }
  }

  return true;

}

void print_grid(int grid[101][101]) {

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }

}