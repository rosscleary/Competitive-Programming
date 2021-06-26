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

  int best_score=0;
  int best;
  for (int i=1; i<=5; i++) {
    int total=0;
    for (int j=1,score; j<=4; j++) {
      cin>>score;
      total+=score;
    }
    if (total>best_score) {
      best_score=total;
      best=i;
    }
  }

  cout<<best<<" "<<best_score<<endl;

  return 0;

}