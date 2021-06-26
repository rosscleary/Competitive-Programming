#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define Ull unsigned long long int

#define sf scanf
#define pf printf

#define mp make_pair
#define pb push_back

const int mod=1000000007;

const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

// ---------- END OF TEMPLATE ----------

int main ()

{

  int N, M;
  sf("%d%d", &N, &M);

  pair<int, int> factories[200000];

  for (int i = 0, p, a; i < N; i++)
  {
    sf("%d%d", &p, &a);
    factories[i] = mp(p, a);
  }

  sort(factories, factories + N);

  ll cost = 0;
  int boxes_left = M;

  for (int i = 0; i < N; i++)
  {
    cost += min(factories[i].second, boxes_left) * factories[i].first;
    boxes_left -= factories[i].second;
    if (boxes_left <= 0) break;
  }

  pf("%lld\n", cost);

  return 0;

}