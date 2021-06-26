#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {

  int n;
  cin>>n;

  int box_sizes[1001][4];

  for (int i=1; i<=n; i++) {
    cin>>box_sizes[i][1];
    cin>>box_sizes[i][2];
    cin>>box_sizes[i][3];
  }

  int m;
  cin>>m;

  for (int test_case=1; test_case<=m; test_case++) {

    int item_size[3];
    cin>>item_size[0]>>item_size[1]>>item_size[2];
    sort(item_size,item_size+3);

    long long smallest_box_size=1000000000000;
    for (int box=1; box<=n; box++) {

      int box_size[3];
      box_size[0]=box_sizes[box][1];
      box_size[1]=box_sizes[box][2];
      box_size[2]=box_sizes[box][3];
      sort(box_size,box_size+3);


      if (item_size[0]<=box_size[0] && item_size[1]<=box_size[1] && item_size[2]<=box_size[2]) {
        if (box_size[0]*box_size[1]*box_size[2]<smallest_box_size) {
          smallest_box_size=box_size[0]*box_size[1]*box_size[2];
        }
      }

    }

    if (smallest_box_size==1000000000000) {
      cout<<"Item does not fit."<<endl;
    }
    else {
      cout<<smallest_box_size<<endl;
    }

  }

  return 0;

}