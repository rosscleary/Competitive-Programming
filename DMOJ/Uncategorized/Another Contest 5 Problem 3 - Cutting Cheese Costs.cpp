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

  int N,K;
  scanf("%d%d",&N,&K);

  vector<pair<ll,ll> > block_values;
  pair<ll,ll> block_costs[100005];
  ll p,d;
  for (int i=0; i<N; i++) {
    scanf("%lld%lld",&p,&d);
    block_values.push_back(make_pair(p-d,i));
    block_costs[i].first=p;
    block_costs[i].second=d;
  }

  sort(block_values.begin(),block_values.end());

  ll answer=0;
  int disc_used=0;
  for (int i=block_values.size()-1; i>=0; i--) {
    if (disc_used<K) {
      answer+=block_costs[block_values[i].second].second;
      disc_used++;
    }
    else {
      answer+=block_costs[block_values[i].second].first;
    }
  }

  printf("%lld\n",answer);

  return 0;

}