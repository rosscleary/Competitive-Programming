#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int r,l;
bool lights[31][9];
int num_patterns=0;
map <vector <bool>, bool> pattern_occured;

void pattern_check(int switch_start) {
  bool lights_copy[31][9];
  for (int row=1; row<=r; row++) {
    for (int col=1; col<=l; col++) {
      lights_copy[row][col]=lights[row][col];
    }
  }
  for (int row=switch_start; row>=2; row--) {
    for (int light=1; light<=l; light++) {
      if (lights_copy[row][light]!=lights_copy[row-1][light]) {
        lights_copy[row-1][light]=true;
      }
      else {
        lights_copy[row-1][light]=false;
      }
    }
  }
  vector <bool> bottom_row;
  for (int light=1; light<=l; light++) {
    bottom_row.push_back(lights_copy[1][light]);
  }
  if (!pattern_occured[bottom_row]) {
    num_patterns++;
    pattern_occured[bottom_row]=true;
  }
}

int main () {
  scanf("%d",&r);
  scanf("%d",&l);
  for (int row=r; row>=1; row--) {
    for (int col=1; col<=l; col++) {
      cin>>lights[row][col];
    }
  }
  for (int switch_start=2; switch_start<=r; switch_start++) {
    pattern_check(switch_start);
  }
  vector <bool> no_switch;
  for (int light=1; light<=l; light++) {
    no_switch.push_back(lights[1][light]);
  }
  if (!pattern_occured[no_switch]) {
    num_patterns++;
  }
  printf("%d",num_patterns);
}