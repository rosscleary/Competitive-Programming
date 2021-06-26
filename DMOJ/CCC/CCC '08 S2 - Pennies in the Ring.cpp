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
using namespace std;

int main () {

  while (1) {

    long long r;
    cin>>r;
    if (!r) {
      break;
    }

    long long square_points=pow(2*r+1,2);
    long long outside_quadrant_points=0;
    for (int i=r; i>=0; i--) {
      for (int j=i; j>=0; j--) {
        if (powl(i,2)+powl(j,2)>powl(r,2)) {
          if (i!=j) {
            outside_quadrant_points+=2;
          }
          else {
            outside_quadrant_points++;
          }
        }
        else {
          break;
        }
      }
    }

    cout<<square_points-(outside_quadrant_points*4)<<endl;

  }

  return 0;

}