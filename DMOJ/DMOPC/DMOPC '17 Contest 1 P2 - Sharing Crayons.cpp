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

  int N;
  ll M;
  scanf("%d%lld",&N,&M);

  map<ll,ll> mod_freq;
  ll answer=0;
  ll c,sum=0;
  mod_freq[0]=1;
  for (int i=0; i<N; i++) {
    scanf("%lld",&c);
    sum+=c;
    answer+=mod_freq[sum%M];
    mod_freq[sum%M]++;
  }

  printf("%lld\n",answer);


  return 0;

}