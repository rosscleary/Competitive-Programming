#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15, MAX_COST = 105;

int N, c[MAX_N], d[MAX_N];
int longest= 0, cheapest = MAX_COST;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> c[i] >> d[i];
    longest = max(longest, d[i]);
  }

  for(int i = 0; i < N; i++) {
    if(d[i] == longest) cheapest = min(cheapest, c[i]);
  }
  
  cout << cheapest << " " << longest << "\n";

  return 0;
}