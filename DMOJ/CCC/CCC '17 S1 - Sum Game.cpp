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

int main () {
  int n;
  scanf("%d",&n);
  int team_1_score_sums[100001];
  int team_2_score_sums[100001];
  int day_score;
  for (int i=1; i<=n; i++) {
    cin>>day_score;
    if (i==1) {
      team_1_score_sums[i]=day_score;
    }
    else {
      team_1_score_sums[i]=team_1_score_sums[i-1]+day_score;
    }
  }
  for (int i=1; i<=n; i++) {
    cin>>day_score;
    if (i==1) {
      team_2_score_sums[i]=day_score;
    }
    else {
      team_2_score_sums[i]=team_2_score_sums[i-1]+day_score;
    }
  }
  int k=0;
  for (int i=n; i>=1; i--) {
    if (team_1_score_sums[i]==team_2_score_sums[i]) {
      k=i;
      break;
    }
  }
  printf("%d",k);
}