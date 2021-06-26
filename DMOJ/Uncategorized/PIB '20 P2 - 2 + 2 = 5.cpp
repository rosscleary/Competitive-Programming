#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll T;

int main ()

{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  ll answer = -1;

  for (ll problem = (T * 14) / 5 - 7; problem <= (T * 14) / 5 + 7; problem++)
  {
    ll time = floor(problem / 2) - floor(problem / 7);
    if (time <= T) answer = problem;
  }

  cout << answer << endl;

  return 0;

}