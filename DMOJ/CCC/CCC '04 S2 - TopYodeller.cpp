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

  int n,k;
  cin>>n>>k;
  int scores[101][101]={0};
  int prefix_sums[101][101]={0};
  for (int i=1; i<=k; i++) {
    for (int j=1; j<=n; j++) {
      cin>>scores[i][j];
      prefix_sums[i][j]=prefix_sums[i-1][j]+scores[i][j];
    }
  }

  int winner_score=-1000000000;
  for (int i=1; i<=n; i++) {
    if (prefix_sums[k][i]>winner_score) {
      winner_score=prefix_sums[k][i];
    }
  }

  vector<int> winners;
  for (int i=1; i<=n; i++) {
    if (prefix_sums[k][i]==winner_score) {
      winners.push_back(i);
    }
  }

  for (int winner=0; winner<winners.size(); winner++) {
    int worst_rank=1;
    for (int i=1; i<=k; i++) {
      int num_higher=0;
      for (int j=1; j<=n; j++) {
        if (prefix_sums[i][j]>prefix_sums[i][winners[winner]]) {
          num_higher++;
        }
      }
      if (num_higher+1>worst_rank) {
        worst_rank=num_higher+1;
      }
    }
    cout<<"Yodeller "<<winners[winner]<<" is the TopYodeller: score "<<winner_score<<", worst rank "<<worst_rank<<endl;
  }

  return 0;

}