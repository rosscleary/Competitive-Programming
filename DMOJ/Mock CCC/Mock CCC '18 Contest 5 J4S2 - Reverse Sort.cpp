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

int main () {

  int n;
  cin>>n;
  int nums[1000];
  for (int i=0; i<n; i++) {
    cin>>nums[i];
  }

  int pair_counter=0;
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      if (nums[i]<nums[j]) {
        pair_counter++;
      }
    }
  }
  cout<<pair_counter<<endl;

  return 0;

}