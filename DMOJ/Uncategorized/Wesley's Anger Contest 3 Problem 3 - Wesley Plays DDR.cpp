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
#define ll long long
using namespace std;

int main () {

  string move_seq;
  cin>>move_seq;

  int M;
  scanf("%d",&M);

  string combo[5];
  map<string,int> combo_value;
  for (int i=0; i<M; i++) {
    cin>>combo[i];
    int value;
    scanf("%d",&value);
    combo_value[combo[i]]=value;
  }

  sort(combo,combo+M);

  int point_count=move_seq.length();
  while (1) {

    if (move_seq.length()==0) {
      break;
    }

    bool combo_found=false;
    for (int i=M-1; i>=0; i--) {
      int find_combo=move_seq.find(combo[i]);
      if (find_combo==0) {
        point_count+=combo_value[combo[i]];
        move_seq.erase(0,combo[i].length());
        combo_found=true;
        break;
      }
    }

    if (!combo_found) {
      move_seq.erase(0,1);
    }

  }

  printf("%d\n",point_count);

  return 0;

}